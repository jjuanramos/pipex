/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:01:49 by juramos           #+#    #+#             */
/*   Updated: 2023/12/12 17:59:40 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	putnbr_base_with_count_fd(unsigned long n, char *base, int fd)
{
	size_t	i;

	i = 0;
	if (n < (unsigned long)ft_strlen(base))
		i += write(fd, &base[n], 1);
	else
	{
		i += putnbr_base_with_count_fd(n / ft_strlen(base), base, fd);
		i += putnbr_base_with_count_fd(n % ft_strlen(base), base, fd);
	}
	return (i);
}

size_t	putnbr_int_with_count_fd(long n, char *base, int fd)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i += write(fd, "-", 1);
		n *= -1;
	}
	if (n < (long)ft_strlen(base))
		i += write(fd, &base[n], 1);
	else
	{
		i += putnbr_int_with_count_fd(n / ft_strlen(base), base, fd);
		i += putnbr_int_with_count_fd(n % ft_strlen(base), base, fd);
	}
	return (i);
}
