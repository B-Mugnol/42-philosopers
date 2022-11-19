/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:54:28 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/19 01:04:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "defines.h"	// UNIT_TO_MICRO macro
# include "error.h"		// generic_error()
# include <stdlib.h>	// EXIT_FAILURE macro
# include <sys/time.h>	// typedef suseconds_t, typedef timeval, gettimeofday()

// time.c
long	time_from_point_usec(struct timeval start);
long	time_from_start_usec(void);

#endif
