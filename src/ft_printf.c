/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:56:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 01:30:06 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>

#include "subspecifiers.h"
#include "specifiers.h"
#include "libft.h"
#include "ft_vector.h"

#include <stdio.h>

const static t_specifier_function	functions[] = {
	signed_integer, signed_integer,
	unsigned_integer,
	error, // o uoctal
	error, // x uhexa
	error, // X uhexa UP
	error, // f float low
	error, // e scient low
	error, // E scient up
	error, // g short low
	error, // G short up
	error, // c char
	error, // s string
	error, // p pointer
	error, // n store
	error // error
};

static int	process_format(t_vector *buffer, const char *format, va_list args)
{
	t_subspecifiers	data;

	format += process_flags(format, &data);
	format += process_width(format, args, &data);
	format += process_precision(format, args, &data);
	format += process_length(format, &data);

	functions[0](buffer, &data, args);
	return (0);
}

int	ft_vprintf(const char *format, va_list args)
{
	const char	*it;
	t_vector	buffer;

	ft_vector_init(&buffer, 100);
	it = format;
	while (*it != '\0')
	{
		if (*it != '%')
		{
			while (*it != '%' && *it != '\0')
				it++;
			if (ft_vector_push_back(&buffer, format, it - format))
			{
				ft_vector_free(&buffer);
				return (-1);
			}
		}
		else
		{
			process_format(&buffer, it, args);
		}
	}
	if (write(1, buffer.data, buffer.size) != buffer.size)
		return (-1);
	return (buffer.size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;

	va_start (args, format);
	ft_vprintf (format, args);
	va_end (args);
	return (0);
}
