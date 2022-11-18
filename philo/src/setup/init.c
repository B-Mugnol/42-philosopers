/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:45:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/19 00:45:57 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

t_philo	*init_philosophers(t_config config, t_table *table)
{
	t_philo	*philo;
	int		index;

	if (config.philosopher_count <= 0)
		return (NULL);
	philo = malloc(config.philosopher_count * sizeof(t_philo));
	if (!philo)
	{
		generic_error(EXIT_FAILURE, "init_philosophers()",
			"malloc failed", NULL);
		return (NULL);
	}
	index = -1;
	while (++index <= config.philosopher_count - 1)
		philo[index] = (t_philo){
			.id = index + 1,
			.eat_count = 0,
			.forks_in_hand = 0,
			.fork[0] = NULL,
			.fork[1] = NULL,
			.table = table,
			.config = config};
	return (philo);
}

t_fork	*init_forks(int fork_count)
{
	t_fork	*fork;
	int		errno;
	int		index;

	if (fork_count <= 0)
		return (NULL);
	fork = malloc(fork_count * sizeof(t_fork));
	if (!fork)
	{
		generic_error(EXIT_FAILURE, "init_forks()", "malloc failed", NULL);
		return (NULL);
	}
	index = -1;
	while (++index <= fork_count - 1)
	{
		errno = pthread_mutex_init(&fork[index].lock, NULL);
		if (errno != 0)
		{
			dismount_forks(index, fork + index - 1);
			generic_error(errno, "init_forks()", "mutex_init failed", NULL);
			return (NULL);
		}
		fork[index].is_available = 1;
	}
	return (fork);
}
