/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 08:56:16 by baubigna          #+#    #+#             */
/*   Updated: 2021/12/15 17:38:43 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int	is_conv(const char c);
int	treat_unsint(unsigned int u);
int	treat_hexa(unsigned int h, int i);
int	treat_char(int c);
int	ft_printf(const char *s, ...);
int	treat_str(char *s);
int	treat_int(int n);
int	treat_ptr(unsigned long l);
int	treat_args(va_list args, const char c);
int	nb_len(int n);

#endif