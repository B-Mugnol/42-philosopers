/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:45:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/02 00:07:25 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*init_philosophers(int philo_count)
{
	t_philo	*philo;

	if (philo_count <= 0)
		return (NULL);
	philo = malloc(philo_count * sizeof(t_philo));
	if (!philo)
	{
		generic_error(EXIT_FAILURE, "init_philosophers()",
			"malloc failed", NULL);
		return (NULL);
	}
	while (philo_count - 1 >= 0)
	{
		philo[philo_count - 1] = (t_philo){
			.id = philo_count,
			.eat_count = 0,
			.curr_action = THINK,
			.last_ate = 0};
		philo_count--;
	}
	return (philo);
}

pthread_mutex_t	*init_forks(int fork_count)
{
	pthread_mutex_t	*fork;
	int				errno;
	int				index;

	if (fork_count <= 0)
		return (NULL);
	fork = malloc(fork_count * sizeof(pthread_mutex_t));
	if (!fork)
	{
		generic_error(EXIT_FAILURE, "init_forks()", "malloc failed", NULL);
		return (NULL);
	}
	index = -1;
	while (++index <= fork_count - 1)
	{
		errno = pthread_mutex_init(&fork[fork_count - 1], NULL);
		if (errno != 0)
		{
			if (index != 0)
				dismount_forks(index, fork + index - 1);
			generic_error(errno, "init_forks()", "mutex_init failed", NULL);
			return (NULL);
		}
	}
	return (fork);
}
