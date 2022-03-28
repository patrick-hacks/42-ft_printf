/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:26:04 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 01:37:24 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subspecifiers.h"

#include <stdint.h>

#include "libft.h"

static const uint32_t flags[4] =
{
	0b00000000000000000000000000000000,
	//
	0b00000000000000000000000000000000,
	// !"#$%&'()*+,-./0123456789:;<=>?
	0b00000000000010000000000000000000,
	//@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_
	0b00000000101010000000100000100000
	//`abcdefghijklmnopqrstuvwxyz{|}~
};

// returns 0 if c is a flag else 1
static int	set_length(unsigned char c, t_subspecifiers *data)
{
	if (c > 127)
		return (1);
	if ((1 << (c % 32) & flags[c / 32]) == 0)
		return (1);
	(data->length[c]++);
	return(0);
}

int	process_length(const char *format, t_subspecifiers *data)
{
	int	i;

	i = 0;
	while (set_length((unsigned char)(format[i]), data) == 0)
		i++;
	return (i);
}
