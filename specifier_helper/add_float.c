/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:14:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/01 12:25:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper.h"

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <math.h>

#include "libft.h"
#include "ft_vector.h"
#include "subspecifier.h"
#include "specifier_helper_float.h"

//#include "libft.h"

// static int	add_float_prefix(char *buffer, t_subspecifiers *subs, double n)
// {
// 	ft_memset(buffer, '\0', 2);
// 	if (subs->flags[' '])
// 		buffer[0] = ' ';
// 	if (subs->flags['+'])
// 		buffer[0] = '+';
// 	if (n < 0)
// 		buffer[0] = '-';
// 	if (buffer[0])
// 		return (0);
// 	return(1);
// }

double get_double_with_length(uint8_t *flags, va_list args)
{
	if (flags['L'] == 1)
		return ((long double)va_arg(args, long double));
	return ((double)va_arg(args, double));
}

int	add_float(t_vector *buffer, t_subspecifiers *subs, double n)
{
	t_double_data	double_data;

	set_double_data(&double_data, n);
	(void) subs;
	ft_vector_push_back(buffer, double_data.str, ft_strlen(double_data.str));
	return (0);
	//+
	//-
	//
	//# decimal
	//0

	// char	nbr_str[20];
	// int		nbr_length;
	// char	prefix[2];
	// int		full_nbr_length;

	// nbr_length = ft_strlen(double_data.str);
	// full_nbr_length = nbr_length + add_float_prefix(prefix, subs, n);

	// if (data->precision > nbr_length - )
	// 	full_nbr_length = data->precision + ft_strlen(prefix);
	// if (data->precision != -1)
	// 	data->flags['0'] = 0;
	// if (!data->flags['-'] && !data->flags['0'])
	// 	ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
	// ft_vector_push_back(buffer, prefix, ft_strlen(prefix));
	// if (!data->flags['-'] && data->flags['0'])
	// 	ft_vector_pad_back(buffer, '0', data->width - full_nbr_length);
	// if (data->precision != -1)
	// 	ft_vector_pad_back(buffer, '0', data->precision - nbr_length);
	// if (data->precision != 0 || nbr.n != 0)
	// 	ft_vector_push_back(buffer, nbr_str, nbr_length);
	// if (data->flags['-'])
	// 	ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
	// return (0);
}
