/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:35:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:23:33 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "defines.h"
# include "error.h"
# include <pthread.h>
# include <stdlib.h>

// simulation.c
int		run_simulation(t_table *table);

// simulation_utils.c
int		protected_pthread_create(pthread_t *thread,
			void *(*start_routine)(void *), void *arg, char *locale);
int		protected_pthread_join(pthread_t thread, char *locale);
int		has_corpse(t_table *table);

#endif
