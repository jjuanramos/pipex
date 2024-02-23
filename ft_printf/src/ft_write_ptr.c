/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:54:21 by juramos           #+#    #+#             */
/*   Updated: 2023/12/12 11:12:31 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_write_ptr(va_list args)
{
	unsigned long		value;
	int					count;

	value = (unsigned long)va_arg(args, void *);
	count = 0;
	if (!value)
		count += write(1, "0x0", 3);
	else
	{
		count += write(1, "0x", 2);
		count += putnbr_base_with_count_fd(value, "0123456789abcdef", 1);
	}
	return (count);
}
