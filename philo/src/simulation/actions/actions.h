/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:00:47 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:02:08 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "defines.h"
# include "time.h"
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// actions.c
void	philo_take_fork(t_fork *fork, t_philo *philo, int *forks_in_hand);
void	philo_die(t_philo *philo, suseconds_t time_to_death);
void	philo_think(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);

// action_utils.c
void	philo_wait_for_fork(t_philo *philo);

#endif
