/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:56:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/25 19:15:39 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>

#include "subspecifier.h"
#include "specifier.h"
#include "libft.h"
#include "ft_vector.h"

#include <stdio.h>

static int	process_format(t_vector *buffer, const char *format, va_list args)
{
	t_subspecifiers	data;
	const char		*it;

	it = format;
	init_t_subspecifiers(&data);
	it += process_flags(it, &data);
	it += process_width(it, args, &data);
	it += process_precision(it, args, &data);
	it += process_length(it, &data);
	if (call_specifier_function(*it, buffer, &data, args) < 0)
	{
		return (1);
	}
	return ((int)(it + 1 - format));
}

int	ft_vprintf(const char *format, va_list args)
{
	const char	*it;
	t_vector	buffer;

	ft_vector_init(&buffer, 100);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			it = format;
			while (*it != '%' && *it != '\0')
				it++;
			if (ft_vector_push_back(&buffer, format, it - format))
			{
				ft_vector_free(&buffer);
				return (-1);
			}
			format = it;
		}
		else
			format += process_format(&buffer, format + 1, args) + 1;
	}
	write(1, buffer.data, buffer.size);
	ft_vector_free(&buffer);
	return (buffer.size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start (args, format);
	return (ft_vprintf(format, args));
	va_end (args);
	return (0);
}
