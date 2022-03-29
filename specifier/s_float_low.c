/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_float_low.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:34:34 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 11:00:20 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"

int	s_float_low(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	//ft_vector_push_back(buffer, "error:", 5);
	(void) buffer;
	(void) data;
	(void) args;
	return (1);
}
