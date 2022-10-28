/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:20:35 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/20 22:29:20 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_config	*get_config(int argc, char **argv)
{
	t_config	*config;

	if (verify_args(argc, argv) == INCORRECT_USAGE)
		return (NULL);
	config = malloc(sizeof(t_config));
	if (!config)
		return (NULL);
	config->philosopher_count = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	if (argv[4])
		config->minimum_eat_count = ft_atoi(argv[4]);
	else
		config->minimum_eat_count = -1;
	return (config);
}
