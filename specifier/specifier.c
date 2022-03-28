/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 03:33:03 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 07:03:39 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier.h"

#include <stdarg.h>
#include <stdint.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "specifier_functions.h"

int	call_specifier_function(char spec, t_vector *buffer,
	t_subspecifiers *data, va_list args)
{
	int8_t function_id;

	if (spec < 64)
	{
		if (spec == '%')
			return (s_percent(buffer, data, args));
		return (s_error(buffer, data, args));
	}
	function_id = spec_function_id[spec - 64];
	return (specifier_functions[function_id](buffer, data, args));
}
