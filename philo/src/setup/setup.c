/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:20:35 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:11:40 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

t_config	get_config(char **argv)
{
	t_config	config;

	config.philosopher_count = ft_atoi(argv[1]);
	config.time_to_die_usec = ft_atoi(argv[2]) * (suseconds_t)(MILLI_TO_MICRO);
	config.time_to_eat_usec = ft_atoi(argv[3]) * (suseconds_t)(MILLI_TO_MICRO);
	config.time_to_sleep_usec = (
			ft_atoi(argv[4]) * (suseconds_t)(MILLI_TO_MICRO)
			);
	if (argv[5])
		config.minimum_eat_count = ft_atoi(argv[5]);
	else
		config.minimum_eat_count = -1;
	return (config);
}

t_table	*get_table(t_config config)
{
	t_table	*table;
	int		errno;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->philo_count = config.philosopher_count;
	table->has_corpse = 0;
	table->philo = init_philosophers(config, table);
	table->fork = NULL;
	if (!table->philo)
		return (dismount_table(table));
	table->fork = init_forks(config.philosopher_count);
	if (!table->fork)
		return (dismount_table(table));
	errno = pthread_mutex_init(&table->lock, NULL);
	if (errno != 0)
	{
		generic_error(errno, "get_table()", "mutex_init failed", NULL);
		return (dismount_table(table));
	}
	return (table);
}
