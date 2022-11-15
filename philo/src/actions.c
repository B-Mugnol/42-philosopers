/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:56:36 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/13 02:50:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"

void	philo_take_fork(t_fork *fork, t_philo *philo, int *forks_in_hand)
{
	if (!fork->is_available)
		return ;
	pthread_mutex_lock(&philo->table->lock);
	if (philo->table->has_corpse)
	{
		pthread_mutex_unlock(&philo->table->lock);
		return ;
	}
	printf("%lims %i has taken a fork\n",
		time_from_start_usec() / MILLI_TO_MICRO,
		philo->id);
	pthread_mutex_unlock(&philo->table->lock);
	fork->is_available = 0;
	if (philo->fork[0] == NULL)
		philo->fork[0] = fork;
	else
		philo->fork[1] = fork;
	*forks_in_hand += 1;
}

void	philo_die(t_philo *philo, suseconds_t time_to_death)
{
	if (time_to_death)
		usleep(time_to_death);
	pthread_mutex_lock(&philo->table->lock);
	if (philo->table->has_corpse == 0)
	{
		printf("%lims %i died\n",
			time_from_start_usec() / MILLI_TO_MICRO,
			philo->id);
		philo->table->has_corpse = 1;
	}
	pthread_mutex_unlock(&philo->table->lock);
}

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock);
	printf("%lims %i is thinking\n",
		time_from_start_usec() / MILLI_TO_MICRO,
		philo->id);
	pthread_mutex_unlock(&philo->table->lock);
	philo_wait_for_fork(philo);
}

void	philo_eat(t_philo *philo)
{
	int				index;
	pthread_mutex_t	*lock[2];

	pthread_mutex_lock(&philo->table->lock);
	printf("%lims %i is eating\n",
		time_from_start_usec() / MILLI_TO_MICRO, philo->id);
	pthread_mutex_unlock(&philo->table->lock);
	if (gettimeofday(&philo->last_ate, NULL) == -1)
		generic_error(EXIT_FAILURE, "gettimeofday()", "function failed", NULL);
	if (philo->config.time_to_eat_usec >= philo->config.time_to_die_usec)
		return (philo_die(philo, philo->config.time_to_die_usec));
	usleep(philo->config.time_to_eat_usec);
	pthread_mutex_lock(&philo->table->lock);
	philo->eat_count += 1;
	pthread_mutex_unlock(&philo->table->lock);
	philo->forks_in_hand = 0;
	index = -1;
	while (++index < 2)
	{
		pthread_mutex_lock(&philo->fork[index]->lock);
		lock[index] = &philo->fork[index]->lock;
		philo->fork[index]->is_available = 1;
		philo->fork[index] = NULL;
		pthread_mutex_unlock(lock[index]);
	}
}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock);
	printf("%lims %i is sleeping\n",
		time_from_start_usec() / MILLI_TO_MICRO,
		philo->id);
	pthread_mutex_unlock(&philo->table->lock);
	if (philo->config.time_to_die_usec - philo->config.time_to_sleep_usec
		> time_from_point_usec(philo->last_ate))
		usleep(philo->config.time_to_sleep_usec);
	else
		philo_die(
			philo,
			philo->config.time_to_die_usec
			- time_from_point_usec(philo->last_ate)
			);
}
