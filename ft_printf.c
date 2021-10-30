/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:25:27 by falarm            #+#    #+#             */
/*   Updated: 2021/10/27 22:47:20 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialise(t_struct *s)
{
	s->accuracy = 0;
	s->minus = 0;
	s->nul = 0;
	s->octopr = 0;
	s->plus = 0;
	s->space = 0;
	s->width = 0;
}

int	ft_type_format(char c, va_list aq, t_struct *s)
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
		res = ft_puthex_f(aq, c, s);
	if (c == '%')
		res += write(1, "%", 1);
	return (res);
}

int	str_to_int(char ***f)
{
	int	n;

	n = 0;
	while (***(f++) != '\0' && ***f >= '0' && ***f <= '9')
		n = (n * 10) + (***f - '0');
	return (n);
}

void	ft_parse_flag(char **f, t_struct *s)
{
	while (**(f++) != '\0' && **f != 'c' && **f != 's'
		&& **f != 'p' && **f != 'd' && **f != 'i'
		&& **f != 'u' && **f != 'x' && **f != 'X'
		&& **f != '%')
	{
		if (**f == '#')
			s->octopr = 1;
		if (**f == '-')
			s->minus = 1;
		if (**f == '0')
			s->nul = 1;
		if (**f == '+')
			s->plus == 1;
		if (**f == ' ')
			s->space = 1;
		if (**f >= 1 && **f <= 9)
			s->width = str_to_int(&f);
		if (**f == '.')
		{
			*f++;
			s->accuracy = str_to_int(&f);
		}
	}
}

int	ft_parser(const char *format, va_list aq, t_struct *s)
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
			res += ft_type_format(*format, aq, &s);
		}
		else
			res += write(1, *format, 1);
		format++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_struct	s;
	int			res;

	va_start(ap, format);
	if (!format)
	{
		write(1, "", 0);
		return (0);
	}
	if (ft_strlen(format) == 1 && *format == '%')
		return (0);
	initialise(&s);
	res = ft_parser(format, ap, &s);
	va_end(ap);
	return (res);
}
