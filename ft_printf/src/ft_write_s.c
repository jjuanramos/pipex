/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:52:05 by juramos           #+#    #+#             */
/*   Updated: 2023/12/11 10:34:32 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_write_s(va_list args)
{
	char	*value;
	size_t	pos;

	pos = 0;
	value = va_arg(args, char *);
	if (!value)
	{
		pos += write(1, "(null)", 6);
		return (pos);
	}
	while (value[pos])
	{
		write(1, &value[pos], 1);
		pos++;
	}
	return (pos);
}
