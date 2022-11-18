/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:44:15 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:23:42 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	protected_pthread_create(pthread_t *thread, void *(*start_routine)(void *),
	void *arg, char *locale)
{
	int	errno;

	errno = pthread_create(thread, NULL, start_routine, arg);
	if (errno != 0)
		generic_error(errno, locale,
			"pthread_create: thread creation failed", NULL);
	return (errno);
}

int	protected_pthread_join(pthread_t thread, char *locale)
{
	int	errno;

	errno = pthread_join(thread, NULL);
	if (errno != 0)
		generic_error(errno, locale,
			"pthread_join: thread join failed", NULL);
	return (errno);
}

int	has_corpse(t_table *table)
{
	pthread_mutex_lock(&table->lock);
	if (table->has_corpse)
	{
		pthread_mutex_unlock(&table->lock);
		return (1);
	}
	pthread_mutex_unlock(&table->lock);
	return (0);
}
