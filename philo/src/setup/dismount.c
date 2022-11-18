/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dismount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:45:45 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/18 23:10:54 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

void	*dismount_forks(int fork_count, t_fork *fork)
{
	int	errno;

	if (fork_count <= 0)
		return (NULL);
	while (fork_count - 1 >= 0)
	{
		errno = pthread_mutex_destroy(&fork[fork_count - 1].lock);
		if (errno != 0)
			generic_error(errno, "dismount_forks()",
				"mutex_destroy failed", NULL);
		fork_count--;
	}
	free(fork);
	return (NULL);
}

void	*dismount_table(t_table *table)
{
	int	errno;

	if (table->philo)
		free(table->philo);
	if (table->fork)
		dismount_forks(table->philo_count, table->fork);
	if (table->philo && table->fork)
	{
		errno = pthread_mutex_destroy(&table->lock);
		if (errno != 0)
			generic_error(errno, "dismount_table()", "mutex_destroy failed",
				NULL);
	}
	free(table);
	return (NULL);
}
