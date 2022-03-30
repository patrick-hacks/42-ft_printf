/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_char.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:34:34 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 13:08:09 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stddef.h>
#include <wctype.h>
#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "libft.h"

// static int	add_wchar(t_vector *buffer, wint_t	c)
// {
// 	if (c & 0b)
// 	{

// 	}
// }

int	s_char(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	unsigned int	c;

	if (!data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - 1);
	c = va_arg(args, int);
	ft_vector_push_back(buffer, &c, 1);
	if (data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - 1);
	return (0);

	// c = (char)va_arg(args, int);
	// // if (data->precision == 0)
	// // 	str_len = 0;
	// if (!data->flags['-'])
	// 	ft_vector_pad_back(buffer, ' ', data->width - str_len);
	// ft_vector_push_back(buffer, &c, str_len);
	// if (data->flags['-'])
	// 	ft_vector_pad_back(buffer, ' ', data->width - str_len);
	// return (0);
}
