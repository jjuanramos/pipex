/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:49:59 by juramos           #+#    #+#             */
/*   Updated: 2024/04/03 16:50:21 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_process(char *cmd, char **env)
{
	char	**cmd_s;
	char	*path;

	cmd_s = ft_split(cmd, ' ');
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

void	here_doc_in(char *wrd, int *p_fd)
{
	char	*ret;

	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, wrd, ft_strlen(wrd)) == 0)
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}

void	here_doc(char *wrd)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(p_fd[0]);
		here_doc_in(wrd, p_fd);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

void	do_pipe(char *cmd, char **envp)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		exec_process(cmd, envp);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_in;
	int	fd_out;
	int	i;

	if (argc < 5)
	{
		ft_putendl_fd("wrong", 2);
		exit(1);
	}
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc < 6)
		{
			ft_putendl_fd("wrong", 2);
			exit(1);
		}
		i = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv[2]);
	}
	else
	{
		i = 2;
		fd_out = open_file(argv[argc - 1], 1);
		fd_in = open_file(argv[1], 0);
		dup2(fd_in, 0);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	dup2(fd_out, 1);
	exec_process(argv[argc - 2], envp);
}
