/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_long_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:56:24 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 09:45:41 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper.h"

//#include "libft.h"
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

#include "libft.h"
#include "ft_vector.h"
#include "subspecifier.h"

// static void	add_precision(t_vector *buffer, t_subspecifiers *data, int nbr_length)
// {
// 	int	padding;

// 	if (data->precision == -1)
// 		return ;
// 	padding = data->precision - nbr_length;
// 	if (padding > 0)
// 		ft_vector_pad_back(buffer, '0', padding);
// }

// static void	add_width(t_vector *buffer, t_subspecifiers *data, int length)
// {
// 	char	padding;

// 	if (data->width - length <= 0)
// 		return ;
// 	padding = ' ';
// 	if (data->flags['0'])
// 		padding = '0';
// 	ft_vector_pad_back(buffer, padding, data->width - length);
// }

unsigned long long get_with_length_unsigned(uint8_t *flags, va_list args)
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

unsigned long long get_with_length_signed(uint8_t *flags, va_list args)
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
	buffer[0] = '\0';
	buffer[1] = '\0';
	buffer[2] = '\0';
	if(!data->flags['#'] || base_length == 10 || nbr.n == 0)
		return (0);
	if (base_length == 8)
	{
		buffer[0] = '0';
		return (1);
	}
	if (base_length == 16 && base[15] == 'f')
	{
		buffer[0] = '0';
		buffer[1] = 'x';
		return (2);
	}
	if (base_length == 16 && base[15] == 'F')
	{
		buffer[0] = '0';
		buffer[1] = 'X';
		return (2);
	}
	return (0);
}

int	add_nbr(t_vector *buffer, t_subspecifiers *data, char *base, t_nbr nbr)
{
	char	nbr_str[20];
	char	prefix[3];
	int		nbr_length;
	int		full_nbr_length;
	char	char_sign;

	nbr_length = sbase(nbr.n, base, nbr_str);
	char_sign = get_sign(data, nbr.sign);
	full_nbr_length = nbr_length + add_prefix(prefix, data, base, nbr);
	if (char_sign)
		full_nbr_length++;
	if (data->precision > full_nbr_length)
		full_nbr_length = data->precision;
	if (data->precision != -1)
		data->flags['0'] = 0;
	if (!data->flags['-'] && !data->flags['0'])
		ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
		//add_width(buffer, data, full_nbr_length);
	if (char_sign)
		ft_vector_push_back(buffer, &char_sign, 1);
	ft_vector_push_back(buffer, prefix, ft_strlen(prefix));
	if (!data->flags['-'] && data->flags['0'])
		ft_vector_pad_back(buffer, '0', data->width - full_nbr_length);
		//add_width(buffer, data, full_nbr_length);
	if (data->precision != -1)
		ft_vector_pad_back(buffer, '0', data->precision - nbr_length);
		//add_precision(buffer, data, nbr_length);
	if (data->precision != 0 || nbr.n != 0)
		ft_vector_push_back(buffer, nbr_str, nbr_length);
	if (data->flags['-'])
		ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
		//add_width(buffer, data, full_nbr_length);
	return (0);
}
