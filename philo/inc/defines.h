/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 01:06:01 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/21 21:16:20 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include <pthread.h>	// typedef pthread_mutex_t
# include <sys/time.h>	// typedef suseconds_t, typedef timeval

// Maximum number of threads per process (found at /proc/sys/kernel/threads-max)
# define MAX_THREADS		127364

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

typedef struct s_fork
{
	int				is_available;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	int				forks_in_hand;
	struct s_fork	*fork[2];
	struct timeval	last_ate;
	struct s_table	*table;
	struct s_config	config;
}	t_philo;

typedef struct s_table
{
	int				philo_count;
	int				has_corpse;
	struct s_philo	*philo;
	struct s_fork	*fork;
	pthread_mutex_t	lock;
}	t_table;

#endif
