/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:05:03 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 22:56:11 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

suseconds_t	time_from_point_usec(struct timeval point)
{
	struct timeval	curr_time;
	suseconds_t		seconds;

	if (gettimeofday(&curr_time, NULL) == -1)
	{
		generic_error(EXIT_FAILURE, "gettimeofday()", "function failed", NULL);
		return (-1);
	}
	seconds = (suseconds_t)(curr_time.tv_sec - point.tv_sec);
	return (seconds * UNIT_TO_MICRO + curr_time.tv_usec - point.tv_usec);
}

suseconds_t	time_from_start_usec(void)
{
	static struct timeval	start_time = {.tv_sec = 0, .tv_usec = 0};
	struct timeval			curr_time;

	if (gettimeofday(&curr_time, NULL) == -1)
	{
		generic_error(EXIT_FAILURE, "gettimeofday()", "function failed", NULL);
		return (-1);
	}
	if (start_time.tv_sec == 0 && start_time.tv_usec == 0)
		start_time = curr_time;
	return (time_from_point_usec(start_time));
}
