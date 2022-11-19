/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 05:14:44 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/19 01:36:31 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"
#include "actions.h"	// philo_eat/sleep/think/wait_for_fork()
#include <unistd.h>		// usleep()
#include <sys/time.h>	// gettimeofday()

static int	sit_philosophers(t_table *table);
static void	*table_manager(void *sim_table);
static void	*philo_routine(void *philosopher);

int	run_simulation(t_table *table)
{
	pthread_t	table_thread;
	int			errno;

	errno = protected_pthread_create(&table_thread, table_manager, table,
			"table simulation");
	if (errno != 0)
		return (errno);
	errno = sit_philosophers(table);
	if (errno != 0)
	{
		protected_pthread_join(table_thread, NULL);
		return (errno);
	}
	return (protected_pthread_join(table_thread, NULL));
}

static int	sit_philosophers(t_table *table)
{
	pthread_t	*philo_thread;
	int			index;
	int			errno;

	philo_thread = malloc(table->philo_count * sizeof(pthread_t));
	if (!philo_thread)
		return (EXIT_FAILURE);
	index = -1;
	pthread_mutex_lock(&table->lock);
	while (++index < table->philo_count)
	{
		errno = protected_pthread_create(&philo_thread[index], philo_routine,
				&table->philo[index], "philosopher simulation");
		if (errno != 0)
			break ;
	}
	pthread_mutex_unlock(&table->lock);
	while (--index >= 0)
	{
		errno = protected_pthread_join(philo_thread[index], "philospher");
		if (errno != 0)
			return (errno);
	}
	free(philo_thread);
	return (errno);
}

static void	*table_manager(void *sim_table)
{
	t_table	*table;
	int		index;
	int		min_meals_eaten;

	table = (t_table *)(sim_table);
	min_meals_eaten = 0;
	while (min_meals_eaten != table->philo[0].config.minimum_eat_count)
	{
		usleep(500);
		if (has_corpse(table))
			return (NULL);
		pthread_mutex_lock(&table->lock);
		min_meals_eaten = table->philo[0].eat_count;
		index = 0;
		if (table->philo[0].config.minimum_eat_count != -1)
			while (++index < table->philo_count)
				if (table->philo[index].eat_count < min_meals_eaten)
					min_meals_eaten = table->philo[index].eat_count;
		pthread_mutex_unlock(&table->lock);
	}
	pthread_mutex_lock(&table->lock);
	if (!table->has_corpse)
		table->has_corpse = 1;
	pthread_mutex_unlock(&table->lock);
	return (NULL);
}

static void	*philo_routine(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)(philosopher);
	pthread_mutex_lock(&philo->table->lock);
	pthread_mutex_unlock(&philo->table->lock);
	if (gettimeofday(&philo->last_ate, NULL) == -1)
		generic_error(EXIT_FAILURE, "gettimeofday()", "function failed", NULL);
	philo_wait_for_fork(philo);
	while (1)
	{
		if (has_corpse(philo->table))
			break ;
		philo_eat(philo);
		if (has_corpse(philo->table))
			break ;
		philo_sleep(philo);
		if (has_corpse(philo->table))
			break ;
		philo_think(philo);
	}
	return (NULL);
}
