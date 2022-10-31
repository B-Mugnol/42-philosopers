/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:05:03 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/31 22:01:17 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

long	time_from_point_usec(struct timeval point)
{
	struct timeval	curr_time;
	long			seconds;

	if (gettimeofday(&curr_time, NULL) == -1)
	{
		generic_error(EXIT_FAILURE, "gettimeofday()", "function failed", NULL);
		return (-1);
	}
	seconds = (long)(curr_time.tv_sec - point.tv_sec);
	return (seconds * UNIT_TO_MICRO + curr_time.tv_usec - point.tv_usec);
}
