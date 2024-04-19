/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:21:01 by juramos           #+#    #+#             */
/*   Updated: 2024/04/19 13:15:38 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_number_of_slices(char const *s, char c)
{
	int	pos;
	int	ret;

	ret = 0;
	pos = 0;
	while (s[pos] != '\0')
	{
		if (s[pos] != c)
		{
			ret++;
			while (s[pos] != c && s[pos] != '\0')
				pos++;
		}
		else
			pos++;
	}
	return (ret);
}

static char	**free_split_mod(char **ret, size_t ret_slice)
{
	while (ret_slice)
		free(ret[ret_slice--]);
	free(ret[ret_slice]);
	free(ret);
	return (0);
}

int	add_to_ret(char **ret, size_t *ret_slice, char const **s)
{
	size_t	start;

	start = 0;
	while (**s != ' ' && **s && ++start)
	{
		if (**s == '\'')
		{
			(*s)++;
			while (**s != '\'' && **s && ++start)
				(*s)++;
		}
		else
			(*s)++;
	}
	ret[(*ret_slice)++] = ft_substr(*s - start, 0, start);
	if (!ret[*ret_slice - 1])
	{
		free_split_mod(ret, *ret_slice);
		return (1);
	}
	return (0);
}

char	**ft_split_mod(char const *s, char c)
{
	size_t	ret_slice;
	char	**ret;

	ret = ft_calloc((get_number_of_slices(s, c) + 1), sizeof(char *));
	if (!ret)
		return (0);
	ret_slice = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (add_to_ret(ret, &ret_slice, &s))
				return (NULL);
		}
		else
			s++;
	}
	return (ret);
}
