/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:34:34 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 12:27:09 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdarg.h>
#include <wchar.h>

#include "ft_vector.h"
#include "subspecifier.h"
#include "libft.h"

int	s_string(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	char	*str;
	int		str_len;

	str = va_arg(args, char *);
	str_len = ft_strlen(str);
	if (data->precision != -1)
	{
		if (data->precision < str_len)
			str_len = data->precision;
	}
	if (!data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - str_len);
	ft_vector_push_back(buffer, str, str_len);
	if (data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - str_len);
	return (0);
}
