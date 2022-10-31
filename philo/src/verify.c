/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:08:02 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/31 20:23:37 by bmugnol-         ###   ########.fr       */
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
					"Invalid argument: numeric argument required", NULL));
		if (ft_atoi(argv[index]) <= 0)
			return (generic_error(INCORRECT_USAGE, argv[0],
					"Invalid argument: argument must be positive", NULL));
		index++;
	}
	return (EXIT_SUCCESS);
}
