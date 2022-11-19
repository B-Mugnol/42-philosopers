/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:51:05 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/19 01:05:41 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>	// write()
# include <sys/time.h>	// typedef timeval, gettimeofday()

// utils.c
int		is_digit_str(const char *str);
int		ft_atoi(const char *s);
int		random_bool(void);
void	ft_putstr_fd(char *s, int fd);

#endif
