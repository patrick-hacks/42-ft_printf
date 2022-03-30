/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hexa_unsigned_low.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:34:34 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 11:04:36 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "specifier_helper.h"

int	s_hexa_unsigned_low(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	t_nbr	nbr;

	data->flags['+'] = 0;
	data->flags[' '] = 0;
	nbr.n = get_with_length_unsigned(data->flags, args);
	nbr.sign = 0;
	return (add_nbr(buffer, data, "0123456789abcdef", nbr));
}
