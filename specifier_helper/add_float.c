/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:14:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 11:54:55 by pfuchs           ###   ########.fr       */
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
	return (0);
}

double	get_float_with_length(uint8_t *flags, va_list args)
{
	if (flags['L'] == 1)
		return ((long double)va_arg(args, long double));
	return ((double)va_arg(args, double));
}

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

int	calc_lengths(t_printed_lengths *lengths, t_double_data *data,
	int frac_left, t_subspecifiers *subs)
{
	lengths->nbr_digits_before = data->whole_digits;
	if (subs->precision | (subs->flags)['#'])
		lengths->dot = 1;
	if (data->whole_digits <= 0)
		lengths->zero_between = data->fractions - (int)ft_strlen(data->str);
	if (lengths->zero_between > subs->precision)
		lengths->zero_between = subs->precision;
	frac_left = subs->precision - lengths->zero_between;
	if (frac_left < 0)
		frac_left = 0;
	if (frac_left <= data->fraction_digits)
		lengths->nbr_digits_after = frac_left;
	if (frac_left > data->fraction_digits)
	{
		lengths->nbr_digits_after = data->fraction_digits;
		lengths->zero_after = frac_left - data->fraction_digits;
	}
	if (lengths->nbr_digits_before < 0)
	{
		lengths->nbr_digits_before = 0;
		lengths->zero_before = 1;
	}
	lengths->full = lengths->prefix + lengths->zero_before
		+ lengths->nbr_digits_before + lengths->dot + lengths->zero_between
		+ lengths->nbr_digits_after + lengths->zero_after;
}

void	add_float_2(t_vector *buffer, t_printed_lengths *lengths,
		t_double_data *data, int fractions)
{
	ft_vector_pad_back(buffer, '0', lengths->zero_before);
	ft_vector_push_back(buffer, data->str, lengths->nbr_digits_before);
	ft_vector_pad_back(buffer, '.', lengths->dot);
	ft_vector_pad_back(buffer, '0', lengths->zero_between);
	ft_vector_push_back(buffer, fractions, lengths->nbr_digits_after);
	ft_vector_pad_back(buffer, '0', lengths->zero_after);
}

int	add_float(t_vector *buffer, t_subspecifiers *subs, double n)
{
	t_double_data		data;
	t_printed_lengths	lengths;
	char				prefix[2];
	char				*fractions;
	int					fractions_left;

	set_float_data(&data, n);
	ft_memset(&lengths, 0, sizeof(t_printed_lengths));
	lengths.prefix = add_float_prefix(prefix, subs, n);
	calc_lengths(&lengths, &data, fractions_left, subs);
	fractions = data.str + data.whole_digits;
	if (fractions < data.str)
		fractions = data.str;
	if (!subs->flags['-'] && !subs->flags['0'])
		ft_vector_pad_back(buffer, ' ', subs->width - lengths.full);
	ft_vector_push_back(buffer, prefix, lengths.prefix);
	if (!subs->flags['-'] && subs->flags['0'])
		ft_vector_pad_back(buffer, '0', subs->width - lengths.full);
	add_float_2(buffer, &lengths, &data, fractions);
	if (subs->flags['-'])
		ft_vector_pad_back(buffer, ' ', subs->width - lengths.full);
	return (0);
}
