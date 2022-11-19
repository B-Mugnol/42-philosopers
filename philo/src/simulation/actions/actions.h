/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:00:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/19 01:04:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "defines.h"	// typedefs, macros
# include "time.h"		// time_from_start_usec(), time_from_point_usec()
# include <unistd.h>	// usleep()
# include <pthread.h>	// typedef pthread_mutex_t, pthread_mutex_lock/unlock()
# include <sys/time.h>	// typedef suseconds_t, gettimeofday()

// actions.c
void	philo_take_fork(t_fork *fork, t_philo *philo, int *forks_in_hand);
void	philo_die(t_philo *philo, suseconds_t time_to_death);
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);

// action_utils.c
void	philo_wait_for_fork(t_philo *philo);

#endif
