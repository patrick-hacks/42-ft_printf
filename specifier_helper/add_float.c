/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 19:14:32 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/31 01:09:20 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper.h"

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <math.h>

#include "libft.h"
#include "ft_vector.h"
#include "subspecifier.h"

//#include "libft.h"

typedef struct s_double_data {
	int			sign;
	int			exp;
	uint64_t	mantissa;
	uint64_t	digits[8];
}	t_double_data;

static void	get_double_digits(t_double_data *data, int offset, int factor)
{
	int	i;
	int exp_i;

	exp_i = data->exp;
	ft_memset(data->digits, 0, 8 * 8);
	(data->digits)[0] = data->mantissa;
	while (exp_i != 0)
	{
		i = 7;
		while (i >= 0)
		{
			(data->digits)[i] *= 2;
			if ((data->digits)[i] >= 100000000000000000UL)
			{
				(data->digits)[i] -= 100000000000000000UL;
				(data->digits)[i+1]++;
			}
			i--;
		}
		exp_i += offset;
	}
}

static void	set_double_data(double n, t_double_data *data)
{
	long long		temp;
	int				offset;
	int				factor;

	temp = *(long long *)&n;
	data->sign = (temp >> 63) & 0x1;
	data->exp = ((temp >> 52) & 0x7FF) - 1075;
	data->mantissa = (temp & 0xfffffffffffff) + 0x10000000000000;
	offset = -1;
	factor = 2;
	if (data->exp < 0)
	{
		offset = 1;
		factor = 5;
	}
	get_double_digits(data, offset, factor);
}

int	add_float(t_vector *buffer, t_subspecifiers *data, char *base, t_nbr nbr)
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
