/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:51:30 by juramos           #+#    #+#             */
/*   Updated: 2024/04/25 12:51:30 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_process(char *cmd, char **env)
{
	char	**cmd_s;
	char	*path;

	cmd_s = ft_split_mod(cmd, ' ');
	path = get_path(cmd_s[0], env);
	if (!path)
	{
		send_to_stderr(cmd_s[0], NULL, "command not found");
		free_split(cmd_s);
		exit(1);
	}
	if (execve(path, cmd_s, env) == -1)
	{
		send_to_stderr(cmd, NULL, strerror(errno));
		free_split(cmd_s);
		exit(1);
	}
}

void	child_process(char **argv, int *p_fd, char **envp)
{
	int	fd;

	fd = open_file(argv[1], 0);
	if (fd == -1)
	{
		send_to_stderr(NULL, argv[1], strerror(errno));
		exit(1);
	}
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec_process(argv[2], envp);
}

void	parent_process(char **argv, int *p_fd, char **envp)
{
	int		fd;
	char	**cmd_s;
	char	*path;

	cmd_s = ft_split(argv[3], ' ');
	path = get_path(cmd_s[0], envp);
	if (!path)
	{
		send_to_stderr(cmd_s[0], NULL, "command not found");
		free_split(cmd_s);
		exit(1);
	}
	free_split(cmd_s);
	fd = open_file(argv[4], 1);
	if (fd == -1)
	{
		send_to_stderr(NULL, argv[1], strerror(errno));
		exit(1);
	}
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec_process(argv[3], envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("./pipex ar1 co1 co2 ar2\n", 2);
		exit(1);
	}
	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		child_process(argv, p_fd, envp);
	parent_process(argv, p_fd, envp);
	return (0);
}
