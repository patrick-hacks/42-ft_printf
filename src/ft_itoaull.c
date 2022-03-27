/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoaull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:37:43 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 04:18:33 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_intlen

#include <stdlib.h> // malloc
#include <stddef.h> // NULL size_t

// Returns the length of an integer in string representation
static int	len(unsigned long long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

// Returns a freeable string representing the int n
char	*ft_itoaull(unsigned long long n)
{
	int		digits;
	char	*str;
	char	*str_end_it;

	digits = len(n);
	str = malloc(digits + 1);
	str_end_it = str + digits;
	if (!str)
		return (NULL);
	*str_end_it = '\0';
	str_end_it--;
	while (str <= str_end_it)
	{
		*str_end_it = (n % 10) + '0';
		str_end_it--;
		n /= 10;
	}
	return (str);
}
