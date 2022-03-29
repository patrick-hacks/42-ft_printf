/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_integer_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:56:02 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 11:02:48 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "specifier_helper.h"

int	s_integer_signed(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	int		val;
	int		sign;

	val = va_arg(args, int);
	sign = 0;
	if (val < 0)
	{
		val *= -1;
		sign = 1;
	}
	return (s_long_long(buffer, data, (unsigned long long)val, sign));
}
