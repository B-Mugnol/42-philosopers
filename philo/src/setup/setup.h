/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:02:59 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/02 01:30:57 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "defines.h"

// setup.c
t_config		*get_config(int argc, char **argv);
t_table			*get_table(int philo_count);

// init.c
t_philo			*init_philosophers(int philo_count, t_table *table);
pthread_mutex_t	*init_forks(int fork_count);

// dismount.c
void			*dismount_forks(int fork_count, pthread_mutex_t *fork);
void			*dismount_table(t_table *table);

#endif
