/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:10:05 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 06:39:13 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subspecifier.h"

#include <stdint.h>

// returns 0 if c is a flag else 1
static int	set_flag(char flag, t_subspecifiers *data)
{
	int	i;

	i = 0;
	while (i < (int)sizeof(FLAG_CHARS))
	{
		if (flag == FLAG_CHARS[i])
		{
			(data->flags)[i]++;
			return (0);
		}
		i++;
	}
	return (1);
}

int	process_flags(const char *format, t_subspecifiers *data)
{
	int	i;

	i = 0;
	while (set_flag((unsigned char)(format[i]), data) == 0)
		i++;
	return (i);
}
