/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:35:27 by juramos           #+#    #+#             */
/*   Updated: 2023/12/12 11:26:34 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
size_t	ft_write_s(va_list args);
size_t	ft_write_c(va_list args);
size_t	ft_write_d(va_list args);
size_t	ft_write_x(va_list args);
size_t	ft_write_x_upper(va_list args);
size_t	ft_write_u(va_list args);
size_t	ft_write_ptr(va_list args);
size_t	putnbr_base_with_count_fd(unsigned long n, char *base, int fd);
size_t	putnbr_int_with_count_fd(long n, char *base, int fd);
#endif