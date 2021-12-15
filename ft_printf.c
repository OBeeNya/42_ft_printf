/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:41:54 by baubigna          #+#    #+#             */
/*   Updated: 2021/12/15 17:42:26 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	is_conv(const char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'd' && c != 'i' && c != 'u'
		&& c != 'x' && c != '%' && c != 'X')
		return (0);
	return (1);
}

int	treat_unsint(unsigned int u)
{
	static int	printedb;

	printedb = 0;
	if (u > 9)
	{
		printedb++;
		treat_unsint(u / 10);
	}
	printedb += treat_char(u % 10 + 48);
	return (printedb);
}

int	treat_hexa(unsigned int h, int i)
{
	char	*base_low;
	char	*base_up;
	int		printedc;

	printedc = 0;
	base_low = "0123456789abcdef";
	base_up = "0123456789ABCDEF";
	if (h < 16)
	{
		if (i == 0)
			printedc += treat_char(base_low[h % 16]);
		else
			printedc += treat_char(base_up[h % 16]);
	}
	else
	{
		printedc += treat_hexa(h / 16, i);
		printedc += treat_hexa(h % 16, i);
	}
	return (printedc);
}

int	treat_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		printed_char;

	i = 0;
	printed_char = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && is_conv(s[i + 1]))
		{
			printed_char += treat_args(args, s[i + 1]);
			i += 2;
		}
		else
		{
			printed_char += treat_char(s[i]);
			i++;
		}
	}
	va_end(args);
	return (printed_char);
}
