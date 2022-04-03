/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:14:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/01 12:25:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper.h"

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <math.h>
#include <string.h>

#include "libft.h"
#include "ft_vector.h"
#include "subspecifier.h"
#include "specifier_helper_float.h"

//#include "libft.h"

static int	add_float_prefix(char *buffer, t_subspecifiers *subs, double n)
{
	ft_memset(buffer, '\0', 2);
	if (subs->flags[' '])
		buffer[0] = ' ';
	if (subs->flags['+'])
		buffer[0] = '+';
	if (n < 0)
		buffer[0] = '-';
	if (n < 1 && n > -1 && buffer[0])
	{
		buffer[1] = '0';
		return (2);
	}
	if (n < 1 && n > -1 && !buffer[0])
	{
		buffer[0] = '0';
		return (1);
	}
	if (buffer[0])
		return (1);
	return(0);
}

double get_float_with_length(uint8_t *flags, va_list args)
{
	if (flags['L'] == 1)
		return ((long double)va_arg(args, long double));
	return ((double)va_arg(args, double));
}

#include <stdio.h>

typedef struct s_printed_lengths
{
	int	prefix;
	int	zero_before;
	int	nbr_digits_before;
	int	dot;
	int	zero_between;
	int	nbr_digits_after;
	int	zero_after;
	int	full;
}	t_printed_lengths;


int	add_float(t_vector *buffer, t_subspecifiers *subs, double n)
{
	t_double_data		data = {0};
	t_printed_lengths	lengths;
	char				prefix[2];
	char				*fractions;
	int					fractions_left;

	set_float_data(&data, n);

	ft_memset(&lengths, 0, sizeof(t_printed_lengths));
	lengths.prefix = add_float_prefix(prefix, subs, n);
	lengths.nbr_digits_before = data.whole_digits;
	if (subs->precision | (subs->flags)['#'])
		lengths.dot = 1;
	if (data.whole_digits <= 0)
		lengths.zero_between = data.fractions - (int)ft_strlen(data.str);
	if (lengths.zero_between > subs->precision)
		lengths.zero_between = subs->precision;
	fractions_left = subs->precision - lengths.zero_between;
	if (fractions_left < 0)
		fractions_left = 0;
	if (fractions_left <= data.fraction_digits)
		lengths.nbr_digits_after = fractions_left;
	if (fractions_left > data.fraction_digits)
	{
		lengths.nbr_digits_after = data.fraction_digits;
		lengths.zero_after = fractions_left - data.fraction_digits;
	}
	if (lengths.nbr_digits_before < 0)
	{
		lengths.nbr_digits_before = 0;
		lengths.zero_before = 1;
	}
	fractions = data.str + data.whole_digits;
	if (fractions < data.str)
		fractions = data.str;

	lengths.full = lengths.prefix + lengths.zero_before + lengths.nbr_digits_before + lengths.dot + lengths.zero_between + lengths.nbr_digits_after + lengths.zero_after;

	// printf("\npre: %d,  ", lengths.prefix);
	// printf("zero: %d,  ", lengths.zero_before);
	// printf("n: %d,  ", lengths.nbr_digits_before);
	// printf("dot: %d,  ", lengths.dot);
	// printf("zero:%d,  ", lengths.zero_between);
	// printf("n: %d\n", lengths.nbr_digits_after);
	// printf("%s\n\n", data.str);
	// printf("whole: %d\n", data.whole_digits);
	// printf("frac: %d\n", data.fractions);
	// printf("length: %ld\n", ft_strlen(data.str));

	if (!subs->flags['-'] && !subs->flags['0'])
		ft_vector_pad_back(buffer, ' ', subs->width - lengths.full);
	ft_vector_push_back(buffer, prefix, lengths.prefix);
	if (!subs->flags['-'] && subs->flags['0'])
		ft_vector_pad_back(buffer, '0', subs->width - lengths.full);
	ft_vector_pad_back(buffer, '0', lengths.zero_before);
	ft_vector_push_back(buffer, data.str, lengths.nbr_digits_before);
	ft_vector_pad_back(buffer, '.', lengths.dot);
	ft_vector_pad_back(buffer, '0', lengths.zero_between);
	ft_vector_push_back(buffer, fractions, lengths.nbr_digits_after);
	ft_vector_pad_back(buffer, '0', lengths.zero_after);
	if (subs->flags['-'])
		ft_vector_pad_back(buffer, ' ', subs->width - lengths.full);
	return (0);


	// if (data->precision > nbr_length - )
	// 	full_nbr_length = data->precision + ft_strlen(prefix);
	// if (data->precision != -1)
	// 	data->flags['0'] = 0;
	// if (!data->flags['-'] && !data->flags['0'])
	// 	ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
	// ft_vector_push_back(buffer, prefix, ft_strlen(prefix));
	// if (!data->flags['-'] && data->flags['0'])
	// 	ft_vector_pad_back(buffer, '0', data->width - full_nbr_length);
	// if (data->precision != -1)
	// 	ft_vector_pad_back(buffer, '0', data->precision - nbr_length);
	// if (data->precision != 0 || nbr.n != 0)
	// 	ft_vector_push_back(buffer, nbr_str, nbr_length);
	// if (data->flags['-'])
	// 	ft_vector_pad_back(buffer, ' ', data->width - full_nbr_length);
	// return (0);
}
