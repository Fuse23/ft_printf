/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:25:46 by falarm            #+#    #+#             */
/*   Updated: 2021/10/27 22:30:39 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft_src/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	int		minus;
	int		nul;
	int		width;
	int		accuracy;
	int		plus;
	int		space;
	int		octopr;
}	t_struct;

int	ft_printf(const char *format, ...);
int	ft_putchr_f(char c);
int	ft_putstr_f(const char *s);
int	ft_putnbr_f(int	n);
int	ft_putunb_f(unsigned int n);
int	ft_hex_f(unsigned int hex, char a);
int	ft_puthex_f(va_list aq, char c);
int	ft_ptr_f(unsigned long hex);
int	ft_putptr_f(va_list vl);
int	ft_type_format(char c, va_list aq);
int	ft_parser(const char *format, va_list aq);

#endif