/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:08:02 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/13 04:01:03 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philosophers.h"

int	verify_args(int argc, char **argv)
{
	size_t		index;

	if (argc != 5 && argc != 6)
		return (generic_error(INCORRECT_USAGE, argv[0],
				"Invalid argument",
				"./philo <number_of_philosophers> <time_to_die> <time_to_eat> \
<time_to_sleep> [<number_of_times_each_philosopher_must_eat>]\
\nTimes must be in milliseconds."));
	index = 0;
	while (argv[++index])
	{
		if (!is_digit_str(argv[index]))
			return (generic_error(INCORRECT_USAGE, argv[0],
					"Invalid argument: numeric (integer) argument required",
					NULL));
		if (ft_atoi(argv[index]) <= 0)
			return (generic_error(INCORRECT_USAGE, argv[0],
					"Invalid argument: argument must be a positive integer",
					NULL));
		if (index == 1 && ft_atoi(argv[index]) > MAX_THREADS - 2)
			return (generic_error(INCORRECT_USAGE, argv[0],
					"Invalid argument: number_of_philosophers exceeds maximum \
allowed (MAX_THREADS).", NULL));
	}
	return (0);
}
