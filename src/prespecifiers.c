/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prespecifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:59:42 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 05:25:15 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prespecifiers.h"

#include <stdarg.h>

#include "libft.h"
#include "format_data.h"

int	process_flags(const char **format)
{
	unsigned char	flag_bits;
	char			c;

	flag_bits = 0;
	c = **format;
	while (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
	{
		if (c == '-')
			flag_bits |= FLAG_MINUS;
		if (c == '+')
			flag_bits |= FLAG_PLUS;
		if (c == ' ')
			flag_bits |= FLAG_SPACE;
		if (c == '#')
			flag_bits |= FLAG_HASH;
		if (c == '0')
			flag_bits |= FLAG_ZERO;
		(*format)++;
		c = **format;
	}
	return (flag_bits);
}

int	process_star_number(const char **num, va_list args)
{
	const char	*it;
	int			number;

	it = *num;
	if (*it == '*')
	{
		it++;
		number = va_arg(args, int);
	}
	else
	{
		number = ft_atoi(it);
		if (ft_isdigit(*it))
			number = -1;
		while (ft_isdigit(*it))
			it++;
	}
	*num = it;
	return (number);
}

int	process_specifier(const char **num)
{
	const char	specifiers[] = "diuoxXfeEgGcspn";
	char		spec;
	int			i;

	spec = **num;
	(*num)++;
	i = 0;
	while (i < 15)
	{
		if (spec == specifiers[i])
			return (i);
		i++;
	}
	return (i);
}
