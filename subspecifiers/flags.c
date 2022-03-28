/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 22:10:05 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 01:37:10 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subspecifiers.h"

#include <stdint.h>

static const uint32_t flags[4] =
{
	0b00000000000000000000000000000000,
	//
	0b11111011110111011111111111111111,
	// !"#$%&'()*+,-./0123456789:;<=>?
	0b10000000000000000000000000011111,
	//@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_
	0b10000000000000000000000000011111
	//`abcdefghijklmnopqrstuvwxyz{|}~
};

// returns 0 if c is a flag else 1
static int	set_flag(unsigned char c, t_subspecifiers *data)
{
	if (c > 127)
		return (1);
	if ((1 << (c % 32) & flags[c / 32]) == 0)
		return (1);
	(data->flags)[c]++;
	return(0);
}

int	process_flags(const char *format, t_subspecifiers *data)
{
	int	i;

	i = 0;
	while (set_flag((unsigned char)(format[i]), data) == 0)
		i++;
	return (i);
}
