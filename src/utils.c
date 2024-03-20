/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:17:12 by juramos           #+#    #+#             */
/*   Updated: 2024/03/20 11:05:38 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_to_stderr(char *co, char *ar, char *err)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putendl_fd(co, 2);
	ft_putstr_fd(": ", 2);
	if (ar)
	{
		ft_putendl_fd(ar, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(err, 2);
}
