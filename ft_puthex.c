/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:54:59 by falarm            #+#    #+#             */
/*   Updated: 2021/10/27 22:55:14 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_f(unsigned int hex, char a)
{
	char	c;
	int		mod;
	int		res;

	res = 0;
	mod = hex % 16;
	hex /= 16;
	if (hex != 0)
		res += ft_hex_f(hex, a);
	if (mod < 10)
		c = mod + '0';
	else
		c = mod + a - 10;
	res += write(1, &c, 1);
	return (res);
}

int	ft_puthex_f(va_list aq, char c, t_struct *s)
{
	char			a;
	unsigned int	hex;
	int				res;

	res = 0;
	a = '\0';
	hex = (unsigned int) va_arg(aq, unsigned int);
	if (c == 'X')
		a = 'A';
	else if (c == 'x')
		a = 'a';
	if (s->octopr)
	{
		if (c == 'X')
			res += write(1, "0X", 2);
		else
			res += write(1, "0x", 2);
	}
	if (s->space)
		res += write(1, " ", 1);
	while (s->width--)
		res += write(1, " ", 1);
	
	return (res);
}

int	ft_ptr_f(unsigned long hex)
{
	char	c;
	int		mod;
	int		res;

	res = 0;
	mod = hex % 16;
	hex /= 16;
	if (hex != 0)
		res += ft_ptr_f(hex);
	if (mod < 10)
		c = mod + '0';
	else
		c = (mod - 10) + 'a';
	res += write(1, &c, 1);
	return (res);
}

int	ft_putptr_f(va_list aq)
{
	unsigned long	ptr;
	int				res;

	res = 0;
	ptr = (unsigned long) va_arg(aq, void *);
	res += write(1, "0x", 2);
	res += ft_ptr_f(ptr);
	return (res);
}
