/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 23:45:08 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 11:03:19 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subspecifier.h"

#include <stdarg.h>

#include "libft.h"

int	process_width(const char *format, va_list args, t_subspecifiers *data)
{
	int	i;

	if (*format == '*')
	{
		data->width = va_arg(args, int);
		return (1);
	}
	data->width = ft_atoi(format);
	i = 0;
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}
