/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sbase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 05:18:56 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 05:31:37 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	recursive_base(unsigned long long number, int base_size,
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
	int		base_size;

	if (nbr == 0)
		output[0] = base[0];
	return(recursive_base(nbr, base_size, base, output));
}
