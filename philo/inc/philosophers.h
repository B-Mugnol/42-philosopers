/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:55:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/20 17:26:12 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define INCORRECT_USAGE	2

typedef struct s_config
{
	int	philosopher_count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	minimum_eat_count;
}	t_config;

// error.c
int			generic_error(int exit_code, char *locale, char *msg, char *usage);

// verify.c
int			verify_args(int argc, char **argv);

// setup.c
t_config	*get_config(int argc, char **argv);

#endif
