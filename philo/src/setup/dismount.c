/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dismount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:45:45 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/11/02 00:12:30 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*dismount_forks(int fork_count, pthread_mutex_t *fork)
{
	int	errno;

	if (fork_count <= 0)
		return (NULL);
	while (fork_count - 1 >= 0)
	{
		errno = pthread_mutex_destroy(&fork[fork_count - 1]);
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

	free(table->philo);
	dismount_forks(table->philo_count, table->fork);
	errno = pthread_mutex_destroy(&(table->lock));
	if (errno != 0)
		generic_error(errno, "dismount_table()", "mutex_destroy failed", NULL);
	free(table);
	return (NULL);
}
