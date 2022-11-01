/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:55:16 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/02 00:13:49 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include "defines.h"
# include "setup.h"

// time.c
long			time_from_point_usec(struct timeval start);
long			time_from_start_usec(void);

// verify.c
int				verify_args(int argc, char **argv);

// error.c
int				generic_error(int exit_code, char *locale, char *msg,
					char *usage);

// utils.c
int				is_digit_str(const char *str);
int				ft_atoi(const char *s);
void			ft_putstr_fd(char *s, int fd);

#endif
