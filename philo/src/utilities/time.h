/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:54:28 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:20:13 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "defines.h"
# include "error.h"
# include <stdlib.h>
# include <sys/time.h>

// time.c
long	time_from_point_usec(struct timeval start);
long	time_from_start_usec(void);

#endif
