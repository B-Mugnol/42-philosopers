/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:08:02 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/31 22:52:20 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	index = 1;
	while (argv[index])
	{
		if (!is_digit_str(argv[index]))
			return (generic_error(INCORRECT_USAGE, argv[0],
					"Invalid argument: numeric (integer) argument required",
					NULL));
		if (ft_atoi(argv[index]) <= 0 || ft_atoi(argv[index]) > UNIT_TO_MICRO)
			return (generic_error(INCORRECT_USAGE, argv[0],
					"Invalid argument: argument must be a positive integer, \
equal to or lesser than 1 million", NULL));
		index++;
	}
	return (EXIT_SUCCESS);
}
