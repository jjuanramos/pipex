/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:51:48 by juramos           #+#    #+#             */
/*   Updated: 2023/12/12 10:55:07 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_write_u(va_list args)
{
	unsigned int	value;
	size_t			i;

	value = va_arg(args, unsigned int);
	i = putnbr_base_with_count_fd(value, "0123456789", 1);
	return (i);
}
