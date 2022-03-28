/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:29:16 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 04:31:18 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

#include "libft.h"
#include "ft_itoaull.h"

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

// static char	get_sign(t_subspecifiers *data, int sign)
// {
// 	if (sign)
// 		return '-';
// 	if (data->flags[0] & 0)
// 		return '+';
// 	if (data->flags[0] & 0)
// 		return ' ';
// 	return '\0';
// }

// static void	add_precision(t_vector *buffer, t_subspecifiers *data, int nbr_length)
// {
// 	int	padding;

// 	if (data->precision == -1)
// 		return ;
// 	padding = data->precision - nbr_length;
// 	if (padding > 0)
// 		ft_vector_pad_back(buffer, '0', padding);
// }

// static void	add_width(t_vector *buffer, t_subspecifiers *data, int nbr_length)
// {
// 	char	padding;

// 	if (data->width - nbr_length <= 0)
// 		return ;
// 	padding = ' ';
// 	if (data->flags[0] & 0)
// 		padding = '0';
// 	ft_vector_pad_back(buffer, padding, data->width - nbr_length);
// }

// void	add_number(t_vector *buffer, t_subspecifiers *data,
// 	unsigned long long n, int sign)
// {
// 	char	*nbr_str;
// 	int		nbr_length;
// 	int		full_length;
// 	char	char_sign;

// 	nbr_str = ft_itoaull(n);
// 	char_sign = get_sign(data, sign);
// 	nbr_length = ft_strlen(nbr_str);
// 	full_length = nbr_length;
// 	if (data->precision > full_length)
// 		full_length = data->precision;
// 	if (char_sign)
// 		full_length++;
// 	if (char_sign && (data->flags[0] & 0))
// 		ft_vector_push_back(buffer, &char_sign, 1);
// 	if (!(data->flags[0] & 0))
// 		add_width(buffer, data, full_length);
// 	if (char_sign && !(data->flags[0] & 0))
// 		ft_vector_push_back(buffer, &char_sign, 1);
// 	if (data->precision != -1)
// 		add_precision(buffer, data, nbr_length);
// 	if (data->precision != 0 || n != 0)
// 		ft_vector_push_back(buffer, nbr_str, nbr_length);
// 	if (data->flags[0] & 0)
// 		add_width(buffer, data, full_length);
// }

// void	unsigned_long_long(t_vector *buffer, t_subspecifiers *data,
// 	va_list args)
// {
// 	unsigned long long	val;

// 	val = va_arg(args, unsigned long long);
// 	add_number(buffer, data, val, 0);
// }

// void	signed_integer(t_vector *buffer, t_subspecifiers *data,
// 	va_list args)
// {
// 	int		val;
// 	int		sign;

// 	val = va_arg(args, int);
// 	sign = 0;
// 	if (val < 0)
// 	{
// 		sign = 1;
// 		val *= -1;
// 	}
// 	add_number(buffer, data, (unsigned long long)val, sign);
// }

// void	unsigned_integer(t_vector *buffer, t_subspecifiers *data,
// 	va_list args)
// {
// 	unsigned int	val;

// 	val = va_arg(args, unsigned int);
// 	add_number(buffer, data, (unsigned long long)val, 0);
// }
