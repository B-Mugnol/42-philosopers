/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:01 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/01 01:08:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define INCORRECT_USAGE	2

# define MILLI_TO_MICRO		1000
# define UNIT_TO_MICRO		1000000

typedef struct s_config
{
	int			philosopher_count;
	suseconds_t	time_to_die_usec;
	suseconds_t	time_to_eat_usec;
	suseconds_t	time_to_sleep_usec;
	int			minimum_eat_count;
}	t_config;

typedef enum e_action
{
	TAKE,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_action;

#endif
