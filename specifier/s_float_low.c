/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_float_low.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:34:34 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/01 12:51:27 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "specifier_helper.h"

int	s_float_low(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	double	nbr;
	nbr = get_double_with_length(data->flags, args);
	return (add_float(buffer, data, nbr));
	//ft_vector_push_back(buffer, "error:", 5);
	(void) buffer;
	(void) data;
	(void) args;
	return (1);
}
