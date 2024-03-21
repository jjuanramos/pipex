/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 12:17:12 by juramos           #+#    #+#             */
/*   Updated: 2024/03/21 12:46:24 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	send_to_stderr(char *co, char *ar, char *err)
{
	char	**tmp;

	ft_putstr_fd("pipex: ", 2);
	if (co)
	{
		tmp = ft_split(co, ' ');
		ft_putstr_fd(tmp[0], 2);
		ft_putstr_fd(": ", 2);
		free_split(tmp);
	}
	if (ar)
	{
		ft_putstr_fd(ar, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(err, 2);
}

void	free_split(char **arr)
{
	int	pos;

	pos = -1;
	while (arr[++pos])
		free(arr[pos]);
	free(arr);
}

int	open_file(char *name, int to_write)
{
	int	ret;

	if (to_write == 0)
		ret = open(name, O_RDONLY, 777);
	if (to_write == 1)
		ret = open(name, O_WRONLY | O_CREAT | O_TRUNC, 777);
	return (ret);
}

static char	*my_getenv(char *key, char **env)
{
	char	*comp;
	int		i;
	int		j;

	i = -1;
	while (env[++i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		comp = ft_substr(env[i], 0, j);
		if (ft_strncmp(key, comp, ft_strlen(key)) == 0)
		{
			free(comp);
			return (&env[i][j + 1]);
		}
		free(comp);
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	char	*path;
	char	*exec;
	char	**env_vars;
	int		i;

	env_vars = ft_split(my_getenv("PATH", env), ':');
	i = -1;
	while (env_vars[++i])
	{
		path = ft_strjoin(env_vars[i], "/");
		exec = ft_strjoin(path, cmd);
		free(path);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_split(env_vars);
			return (exec);
		}
		free(exec);
	}
	free_split(env_vars);
	return (NULL);
}
