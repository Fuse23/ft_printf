/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:25:05 by falarm            #+#    #+#             */
/*   Updated: 2021/10/27 21:50:01 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_format(char c, va_list aq)
{
	int	res;

	res = 0;
	if (c == 'c')
		res = ft_putchr_f((char) va_arg(aq, int));
	if (c == 's')
		res = ft_putstr_f((char *) va_arg(aq, char *));
	if (c == 'p')
		res = ft_putptr_f(aq);
	if (c == 'd' || c == 'i')
		res = ft_putnbr_f((int) va_arg(aq, int));
	if (c == 'u')
		res = ft_putunb_f((unsigned int) va_arg(aq, unsigned int));
	if (c == 'x' || c == 'X')
		res = ft_puthex_f(aq, c);
	if (c == '%')
		res += write(1, "%", 1);
	return (res);
}

int	ft_parser(const char *format, va_list aq)
{
	int	res;

	res = 0;
	while (*format != '\0')
	{
		// if (format[i] != '%')
		// 	res += write(1, &format[i], 1);
		// else if (format[i] == '%' && format[i + 1] != '\0'
		// 		&& ft_strchr("cspdiuxX%", format[i + 1]))
		// 		res += ft_type_format(format[++i], aq);
		if (format == '%')
		{
			ft_parse_flag(&format, &s);
		}
		else
			res += write(1, *format, 1);
		format++;
	}
	return (res);
}
