/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:52:50 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:25:34 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "setup.h"
#include "simulation.h"

static int	verify_args(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_config	config;
	t_table		*table;
	int			errno;

	if (verify_args(argc, argv) != 0)
		return (INCORRECT_USAGE);
	config = get_config(argv);
	table = get_table(config);
	if (!table)
		return (EXIT_FAILURE);
	errno = run_simulation(table);
	dismount_table(table);
	return (errno);
}

static int	verify_args(int argc, char **argv)
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
