/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:23 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/24 20:26:23 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "utils.h"	// random_bool()

static void	philo_try_fork(t_philo *philo, t_fork *fork);

void	philo_wait_for_fork(t_philo *philo)
{
	while (philo->forks_in_hand < 2)
	{
		if (time_from_point_usec(philo->last_ate)
			>= philo->config.time_to_die_usec)
			return (philo_die(philo, 0));
		pthread_mutex_lock(&philo->table->lock);
		if (random_bool())
		{
			pthread_mutex_unlock(&philo->table->lock);
			philo_try_fork(philo, &philo->table->fork[philo->id - 1]);
		}
		else
		{
			pthread_mutex_unlock(&philo->table->lock);
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
