/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 05:18:56 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 06:57:49 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper.h"

#include "libft.h"

static int	recursive_base(unsigned long long number, int base_size,
	char *c, char *output)
{
	int	offset;

	if (number)
	{
		offset = recursive_base(number / base_size, base_size, c, output);
		output[offset] = c[number % base_size];
		return (offset + 1);
	}
	return (0);
}

int	sbase(unsigned long long nbr, char *base, char *output)
{
	if (nbr == 0)
	{
		output[0] = base[0];
		return (1);
	}
	return(recursive_base(nbr, ft_strlen(base), base, output));
}
