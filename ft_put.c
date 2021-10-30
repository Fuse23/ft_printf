/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:50:12 by falarm            #+#    #+#             */
/*   Updated: 2021/10/29 19:13:16 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchr_f(char c, int minus, int width)
{
	int	res;

	res = 0;
	if (minus && width)
	{
		res += write(1, &c, 1);
		while (--width >= 0)
			res += write(1, &c, 1);
	}
	if (width)
		while (--width >= 0)
			res += write(1, &c, 1);
	if (!width && !minus)
		res += write(1, &c, 1);
	return (res);
}

int	ft_putstr_f(const char *s, int width, int accuracy, int minus)
{
	int	res;

	res = 0;
	if (s)
	{
		width -= ft_strlen(s);
		if (accuracy)
		{
			if (!minus)
				while (--width >= 0)
					res += write(1, " ", 1);
			while (*s && --accuracy >= 0)
				res += write(1, *s++, 1);
			if (minus)
				while (--width >= 0)
					res += write(1, " ", 1);
		}
		else
			while (*s)
				res += write(1, *s++, 1);
	}
	else
		res += write(1, "(null)", 6);
	return (res);
}

int	ft_putnbr_f(int	n)
{
	unsigned int	num;
	int				res;

	res = 0;
	if (n < 0)
	{
		res += ft_putchr_f('-');
		num = (unsigned int) -n;
	}
	else
		num = (unsigned int) n;
	if (num >= 10)
	{
		res += ft_putnbr_f(num / 10);
		res += ft_putnbr_f(num % 10);
	}
	else
		res += ft_putchr_f(num + '0');
	return (res);
}

int	ft_putunb_f(unsigned int n)
{
	int	res;

	res = 0;
	if (n >= 10)
	{
		res += ft_putnbr_f(n / 10);
		res += ft_putnbr_f(n % 10);
	}
	else
		res += ft_putchr_f(n + '0');
	return (res);
}
