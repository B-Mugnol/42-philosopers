/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:01 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/02 01:30:37 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>
# include <sys/time.h>

# define INCORRECT_USAGE	2

# define MILLI_TO_MICRO		1000
# define UNIT_TO_MICRO		1000000

typedef enum e_action
{
	TAKE,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_action;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	t_action		curr_action;
	suseconds_t		last_ate;
	struct s_table	*table;
}	t_philo;

typedef struct s_config
{
	int			philosopher_count;
	suseconds_t	time_to_die_usec;
	suseconds_t	time_to_eat_usec;
	suseconds_t	time_to_sleep_usec;
	int			minimum_eat_count;
}	t_config;

typedef struct s_table
{
	int				philo_count;
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
}	t_table;

#endif
