/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:05:53 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 22:56:31 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static size_t	ft_strlen(const char *s)
{
	const char	*p;

	p = s;
	while (*p != '\0')
		p++;
	return (p - s);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		return ;
	}
	write(fd, s, ft_strlen(s));
}

int	is_digit_str(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	ft_atoi(const char *s)
{
	int	num;
	int	sign;

	num = 0;
	sign = 1;
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		num = 10 * num + *s - ('0' - 0);
		s++;
	}
	return (num * sign);
}

int	random_bool(void)
{
	static long		seed = 0;
	struct timeval	curr_time;

	if (seed == 0)
	{
		seed = 42;
		if (gettimeofday(&curr_time, NULL) == -1)
			return (seed & 1);
		if (curr_time.tv_usec < 2147483647)
			seed = curr_time.tv_usec;
	}
	seed = (1103515245 * seed + 12345) % 2147483647;
	return (seed & 1);
}
