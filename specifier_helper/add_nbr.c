/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:56:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 11:01:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper.h"

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_vector.h"
#include "subspecifier.h"

unsigned long long	get_with_length_unsigned(uint8_t *flags, va_list args)
{
	if (flags['h'] == 2)
		return ((unsigned char)va_arg(args, unsigned int));
	if (flags['h'] == 1)
		return ((unsigned short)va_arg(args, unsigned int));
	if (flags['l'] == 1)
		return ((unsigned long)va_arg(args, unsigned long));
	if (flags['l'])
		return ((unsigned long long)va_arg(args, unsigned long long));
	if (flags['j'])
		return ((uintmax_t)va_arg(args, uintmax_t));
	if (flags['z'])
		return ((size_t)va_arg(args, size_t));
	if (flags['t'])
		return ((ptrdiff_t)va_arg(args, ptrdiff_t));
	return ((unsigned int)va_arg(args, unsigned int));
}

unsigned long long	get_with_length_signed(uint8_t *flags, va_list args)
{
	if (flags['h'] == 2)
		return ((char)va_arg(args, int));
	if (flags['h'] == 1)
		return ((short)va_arg(args, int));
	if (flags['l'] == 1)
		return ((long)va_arg(args, long));
	if (flags['l'])
		return ((long long)va_arg(args, long long));
	if (flags['j'])
		return ((uintmax_t)va_arg(args, intmax_t));
	if (flags['z'])
		return ((size_t)va_arg(args, size_t));
	if (flags['t'])
		return ((ptrdiff_t)va_arg(args, ptrdiff_t));
	return ((unsigned long long)(int)va_arg(args, int));
}

int	add_prefix(char *buffer, t_subspecifiers *data, char *base, t_nbr nbr)
{
	int	base_length;

	base_length = ft_strlen(base);
	ft_memset(buffer, '\0', 3);
	if (base_length == 10)
	{
		if (data->flags[' '])
			buffer[0] = ' ';
		if (data->flags['+'])
			buffer[0] = '+';
		if (nbr.sign)
			buffer[0] = '-';
		if (buffer[0])
			return (1);
		return (0);
	}
	if (!data->flags['#'] || nbr.n == 0)
		return (0);
	buffer[0] = '0';
	if (base_length == 8)
		return (1);
	buffer[1] = 'x';
	if (base[15] == 'F')
		buffer[1] = 'X';
	return (2);
}

int	add_nbr(t_vector *buffer, t_subspecifiers *data, char *base, t_nbr nbr)
{
	char	nbr_str[20];
	int		nbr_length;
	char	prefix[3];
	int		full_nbr_length;

	full_nbr_length = add_prefix(prefix, data, base, nbr);
	nbr_length = sbase(nbr.n, base, nbr_str);
	nbr_str[nbr_length] = '\0';
	full_nbr_length += nbr_length;
	if (data->precision > nbr_length)
		full_nbr_length = data->precision + ft_strlen(prefix);
	if (data->precision != -1)
		data->flags['0'] = 0;
	if (!data->flags['-'] && !data->flags['0'])
		ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
	ft_vector_push_back(buffer, prefix, ft_strlen(prefix));
	if (!data->flags['-'] && data->flags['0'])
		ft_vector_pad_back(buffer, '0', data->width - full_nbr_length);
	if (data->precision != -1)
		ft_vector_pad_back(buffer, '0', data->precision - nbr_length);
	if (data->precision != 0 || nbr.n != 0)
		ft_vector_push_back(buffer, nbr_str, nbr_length);
	if (data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
	return (0);
}
