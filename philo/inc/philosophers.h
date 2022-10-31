/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:55:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/31 22:04:06 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>

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

// setup.c
t_config	*get_config(int argc, char **argv);

// time.c
long	time_from_point_usec(struct timeval start);

// verify.c
int			verify_args(int argc, char **argv);

// error.c
int			generic_error(int exit_code, char *locale, char *msg, char *usage);

// utils.c
int			is_digit_str(const char *str);
int			ft_atoi(const char *s);
void		ft_putstr_fd(char *s, int fd);

#endif
