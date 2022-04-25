/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pointer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:34:34 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/25 18:45:13 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "specifier_helper.h"

int	s_pointer(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	t_nbr	nbr;

	data->flags['+'] = 0;
	data->flags[' '] = 0;
	data->flags['#'] = 1;
	nbr.n = va_arg(args, size_t);
	if (nbr.n == 0)
	{
		if (!data->flags['-'])
			ft_vector_pad_back(buffer, ' ', data->width - 3);
		ft_vector_push_back(buffer, "0x0", 3);
		if (data->flags['-'])
			ft_vector_pad_back(buffer, ' ', data->width - 3);
		return (0);
	}
	nbr.sign = 0;
	return (add_nbr(buffer, data, "0123456789abcdef", nbr));
}
