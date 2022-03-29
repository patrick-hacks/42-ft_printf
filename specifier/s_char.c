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

#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "libft.h"

int	s_char(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	char	c;
	int		str_len;

	c = (char)va_arg(args, int);
	str_len = 1;
	// if (data->precision == 0)
	// 	str_len = 0;
	if (!data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - str_len);
	ft_vector_push_back(buffer, &c, str_len);
	if (data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - str_len);
	return (0);
}
