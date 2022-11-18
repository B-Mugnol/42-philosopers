/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:23 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:02:13 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "utils.h"

static void	philo_try_fork(t_philo *philo, t_fork *fork);

void	philo_wait_for_fork(t_philo *philo)
{
	while (philo->forks_in_hand < 2)
	{
		if (time_from_point_usec(philo->last_ate)
			>= philo->config.time_to_die_usec)
			return (philo_die(philo, 0));
		if (random_bool())
			philo_try_fork(philo, &philo->table->fork[philo->id - 1]);
		else
		{
			if (philo->id == 1)
				philo_try_fork(philo,
					&philo->table->fork[philo->table->philo_count - 1]);
			else
				philo_try_fork(philo,
					&philo->table->fork[philo->id - 2]);
		}
		usleep(5);
	}
}

static void	philo_try_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->lock);
	if (fork->is_available)
		philo_take_fork(fork, philo, &philo->forks_in_hand);
	pthread_mutex_unlock(&fork->lock);
}
