/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:02:59 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:10:42 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "defines.h"
# include "error.h"
# include <stdlib.h>
# include <pthread.h>

// setup.c
t_config	get_config(char **argv);
t_table		*get_table(t_config config);

// init.c
t_philo		*init_philosophers(t_config config, t_table *table);
t_fork		*init_forks(int fork_count);

// dismount.c
void		*dismount_forks(int fork_count, t_fork *fork);
void		*dismount_table(t_table *table);

#endif
