/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:35:43 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/19 01:13:45 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "defines.h"	// typedefs, macros
# include "error.h"		// generic_error()
# include <stdlib.h>	// malloc(), free(), macros
# include <pthread.h>	// typedef pthread_t, pthread_create/join(),
						// typedef pthread_mutex_t, pthread_mutex_lock/unlock()

// simulation.c
int	run_simulation(t_table *table);

// simulation_utils.c
int	protected_pthread_create(pthread_t *thread,	void *(*start_routine)(void *),
		void *arg, char *locale);
int	protected_pthread_join(pthread_t thread, char *locale);
int	has_corpse(t_table *table);

#endif
