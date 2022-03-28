/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_long_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:56:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 06:55:00 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdarg.h>

#include "libft.h"
#include "specifier_helper.h"
#include "ft_vector.h"
#include "subspecifier.h"

static void	add_precision(t_vector *buffer, t_subspecifiers *data, int nbr_length)
{
	int	padding;

	if (data->precision == -1)
		return ;
	padding = data->precision - nbr_length;
	if (padding > 0)
		ft_vector_pad_back(buffer, '0', padding);
}

static void	add_width(t_vector *buffer, t_subspecifiers *data, int length)
{
	char	padding;

	if (data->width - length <= 0)
		return ;
	padding = ' ';
	if (data->flags['0'])
		padding = '0';
	ft_vector_pad_back(buffer, padding, data->width - length);
}

int	s_long_long(t_vector *buffer, t_subspecifiers *data,
	unsigned long long n, int sign)
{
	char	nbr_str[20];
	int		nbr_length;
	int		full_nbr_length;
	char	char_sign;

	nbr_length = sbase(n, "0123456789", nbr_str);
	char_sign = get_sign(data, sign);
	full_nbr_length = nbr_length;
	if (data->precision > full_nbr_length)
		full_nbr_length = data->precision;
	if (char_sign)
		full_nbr_length++;
	if (char_sign && (data->flags[0] & 0))
		ft_vector_push_back(buffer, &char_sign, 1);
	if (!(data->flags[0] & 0))
		add_width(buffer, data, full_nbr_length);
	if (char_sign && !(data->flags['0']))
		ft_vector_push_back(buffer, &char_sign, 1);
	if (data->precision != -1)
		add_precision(buffer, data, nbr_length);
	if (data->precision != 0 || n != 0)
		ft_vector_push_back(buffer, nbr_str, nbr_length);
	if (data->flags[0] & 0)
		add_width(buffer, data, full_nbr_length);
	return (0);
}
