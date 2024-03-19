/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:49:59 by juramos           #+#    #+#             */
/*   Updated: 2024/03/19 11:43:09 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks -q pipex");
}

int	main(int argc, char *argv[])
{
	char	**commands;
	char	**archives;

	if (argc == 5)
	{
		commands = get_commands(argv);
		archives = get_archives(argv);
		if (!commands || !archives)
			print_and_exit(2, "Failed during the retrieval of args\n", 1);
	}
}
