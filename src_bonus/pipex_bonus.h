/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2024/04/03 10:09:45 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "include/ft_printf.h"
# include "include/libft.h"
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>

/* utils */
void	send_to_stderr(char *co, char *ar, char *err);
void	free_split(char **arr);
int		open_file(char *name, int to_write);
char	*get_path(char *cmd, char **env);

#endif
