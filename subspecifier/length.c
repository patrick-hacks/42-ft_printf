/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:26:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 11:03:08 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subspecifier.h"

#include <stdint.h>

#include "libft.h"

// returns 0 if c is a flag else 1
static int	set_length(unsigned char c, t_subspecifiers *data)
{
	int	i;

	i = 0;
	while (i < (int) sizeof(LENGTH_CHARS))
	{
		if (c == LENGTH_CHARS[i])
		{
			(data->flags)[(int)c]++;
			return (0);
		}
		i++;
	}
	return (1);
}

int	process_length(const char *format, t_subspecifiers *data)
{
	int	i;

	i = 0;
	while (set_length(format[i], data) == 0)
		i++;
	return (i);
}
