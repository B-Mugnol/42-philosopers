/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:22:05 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/10/20 21:18:47 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	generic_error(int exit_code, char *locale, char *msg, char *usage)
{
	if (locale)
	{
		ft_putstr_fd(locale, 2);
		if (msg)
			ft_putstr_fd(": ", 2);
		else
			ft_putstr_fd("\n", 2);
	}
	if (msg)
		ft_putendl_fd(msg, 2);
	if (usage)
	{
		ft_putstr_fd("Usage: ", 2);
		ft_putendl_fd(usage, 2);
	}
	return (exit_code);
}
