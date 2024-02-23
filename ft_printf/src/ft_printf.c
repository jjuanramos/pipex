/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:01:54 by juramos           #+#    #+#             */
/*   Updated: 2023/12/12 12:01:14 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	route_and_write(char type, va_list args)
{
	size_t	count;

	count = 0;
	if (type == 's')
		count += ft_write_s(args);
	else if (type == 'c')
		count += ft_write_c(args);
	else if (type == 'd' || type == 'i')
		count += ft_write_d(args);
	else if (type == 'u')
		count += ft_write_u(args);
	else if (type == 'x')
		count += ft_write_x(args);
	else if (type == 'X')
		count += ft_write_x_upper(args);
	else if (type == 'p')
		count += ft_write_ptr(args);
	else
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	size_t	pos;
	size_t	count;

	pos = 0;
	count = 0;
	va_start(args, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			count += route_and_write(format[pos], args);
		}
		else
			count += write(1, &format[pos], 1);
		pos++;
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
	int		val_s_p;
	int		val_s_ft;
	int		val_c_p;
	int		val_c_ft;
	int		val_i_p;
	int		val_i_ft;
	int		val_u_p;
	int		val_u_ft;
	int		val_x_p;
	int		val_x_ft;
	int		val_ptr_p;
	int		val_ptr_ft;

	printf("Testing p input...\n");
	printf("-----------------------\n");
	printf("std printf:\n\n");
	printf("1: %p.\n", (void *)-14523);
	printf("2: 0x%p-.\n", (void *)0xFFFFFFFFUL);
	printf("3: %pp%p%p.\n", (void *)2147483647 + 423856,
		(void *)0, (void *)2147483647);
	printf("-----------------------\n");
	ft_printf("ft_printf:\n\n");
	ft_printf("1: %p.\n", (void *)-14523);
	ft_printf("2: 0x%p-.\n", (void *)0xFFFFFFFFUL);
	ft_printf("3: %pp%p%p.\n", (void *)2147483647 + 423856, (void *)0,
		(void *)2147483647);
	printf("-----------------------\n");
	printf("-----------------------\n");
	printf("-----------------------\n");
	printf("std printf:\n\n");
	printf("3. Hello %s.\n", "\0");
	printf("4. Hello %s.\n", "juan");
	printf("5. Hello %s %s.\n", "juan", "ramos");
	// printf("6. Hello %s%\n", "juan");
	printf("7. Hello %s%%\n", "juan");
	printf("-----------------------\n");
	ft_printf("ft_printf:\n\n");
	ft_printf("1. Hello\n");
	// seg. fault ft_printf("2. Hello %s.\n", 5);
	ft_printf("3. Hello %s.\n", "\0");
	ft_printf("4. Hello %s.\n", "juan");
	ft_printf("5. Hello %s %s.\n", "juan", "ramos");
	// ft_printf("6. Hello %s%\n", "juan");
	ft_printf("7. Hello %s%%\n", "juan");
	ft_printf("\n-----------------------\n\n");
	printf("Testing character input...\n");
	printf("-----------------------\n");
	printf("std printf:\n\n");
	printf("1. Hello %c.\n", '\0');
	printf("2. Hello %c.\n", 'c');
	printf("3. Hello %c %c.\n", 'c', 'x');
	// printf("4. Hello %c%\n", 'c');
	printf("5. Hello %c%%\n", 'j');
	printf("-----------------------\n");
	ft_printf("ft_printf:\n\n");
	ft_printf("1. Hello %c.\n", '\0');
	ft_printf("2. Hello %c.\n", 'c');
	ft_printf("3. Hello %c %c.\n", 'c', 'x');
	// ft_printf("4. Hello %c%\n", 'c');
	ft_printf("5. Hello %c%%\n", 'j');

	val_s_ft = ft_printf("Hello ft: %s\n", "bye juan");
	val_s_p = printf("Hello  p: %s\n", "bye juan");
	printf("val_s_p is %d, val_s_ft is %d.\n", val_s_p, val_s_ft);
	val_c_ft = ft_printf("Hello ft: %c\n", 'c');
	val_c_p = printf("Hello  p: %c\n", 'c');
	printf("val_c_p is %d, val_c_ft is %d.\n", val_c_p, val_c_ft);
	val_i_ft = ft_printf("Hello ft: %i\n", 1304);
	val_i_p = printf("Hello  p: %i\n", 1304);
	printf("val_i_p is %i, val_i_ft is %i.\n", val_i_p, val_i_ft);
	val_u_ft = ft_printf("Hello ft: %u\n", 10330304);
	val_u_p = printf("Hello  p: %u\n", 10330304);
	printf("val_i_p is %i, val_i_ft is %i.\n", val_u_p, val_u_ft);
	val_x_ft = ft_printf("Hello ft: %x\n", 0x0a);
	val_x_p = printf("Hello  p: %x\n", 0x0a);
	printf("val_x_p is %d, val_x_ft is %d.\n", val_x_p, val_x_ft);
	val_ptr_ft = ft_printf("Hello ft: %p\n", (void *)&val_s_ft);
	val_ptr_p = printf("Hello  p: %p\n", (void *)&val_s_ft);
	printf("val_ptr_p is %i, val_ptr_ft is %i.\n", val_ptr_p, val_ptr_ft);
	return (0);
}
*/