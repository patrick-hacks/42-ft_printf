/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:56:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 04:12:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <unistd.h>

#include "libft.h"
#include "ft_vector.h"
#include "prespecifiers.h"
#include "specifiers.h"

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

static int	process_format(t_vector *buffer, const char **format, va_list args)
{
	t_format_data				data;
	const char					*it;
	it = *format + 1;
	// printf("format %%: %s\n", it);
	// fflush(stdout);
	if (*it == '%')
	{
		if (ft_vector_push_back(buffer, it, 1))
		{
			ft_vector_free(buffer);
			return (-1);
		}
		*format = it + 1;
		return (0);
	}
	// printf("format bits : %s\n", it);
	// fflush(stdout);
	data.flag_bits = process_flags(&it);
	// printf("format width: %s\n", it);
	// fflush(stdout);
	data.width = process_star_number(&it, args);
	// printf("format preci: %s\n", it);
	// fflush(stdout);
	//write(1, "width complete", 14);
	if (*it == '.')
	{
		it++;
		data.precision = process_star_number(&it, args);
	}
	// printf("format id: %s\n", it);
	// fflush(stdout);
	data.specifier_id = process_specifier(&it);
	// printf("format end: %s\n", it);
	// fflush(stdout);
	if (data.specifier_id == -1)
		return (1);
	*format = it;
	functions[data.specifier_id](buffer, &data, args);
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
			process_format(&buffer, &it, args);
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
