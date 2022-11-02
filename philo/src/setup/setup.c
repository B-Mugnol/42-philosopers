/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:20:35 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/02 01:28:01 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "philosophers.h"

t_config	*get_config(int argc, char **argv)
{
	t_config	*config;

	if (verify_args(argc, argv) == INCORRECT_USAGE)
		return (NULL);
	config = malloc(sizeof(t_config));
	if (!config)
	{
		generic_error(EXIT_FAILURE, "get_config", "malloc failed", NULL);
		return (NULL);
	}
	config->philosopher_count = ft_atoi(argv[1]);
	config->time_to_die_usec = ft_atoi(argv[2]) * (suseconds_t)(MILLI_TO_MICRO);
	config->time_to_eat_usec = ft_atoi(argv[3]) * (suseconds_t)(MILLI_TO_MICRO);
	config->time_to_sleep_usec = (
			ft_atoi(argv[4]) * (suseconds_t)(MILLI_TO_MICRO)
			);
	if (argv[4])
		config->minimum_eat_count = ft_atoi(argv[4]);
	else
		config->minimum_eat_count = -1;
	return (config);
}

t_table	*get_table(int philo_count)
{
	t_table	*table;
	int		errno;

	table = malloc(sizeof(t_table));
	if (!table)
	{
		generic_error(EXIT_FAILURE, "get_table", "malloc failed", NULL);
		return (NULL);
	}
	table->philo_count = philo_count;
	table->philo = init_philosophers(philo_count, table);
	if (!table->philo)
		return (NULL);
	table->fork = init_forks(philo_count);
	if (!table->fork)
	{
		free(table->philo);
		return (NULL);
	}
	errno = pthread_mutex_init(&(table->lock), NULL);
	if (errno != 0)
		generic_error(errno, "get_table", "mutex_init failed", NULL);
	if (errno != 0)
		return (dismount_table(table));
	return (table);
}
