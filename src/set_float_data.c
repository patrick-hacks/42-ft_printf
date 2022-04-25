/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_float_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:30:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 11:28:00 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper_float.h"
#include "specifier_helper.h"

#include "libft.h"

static void	get_double_digits(t_double_data *data, int offset, int factor)
{
	int	i;
	int	exp_i;

	exp_i = data->exp;
	ft_memset(data->digits, 0, 30 * 8);
	(data->digits)[0] = data->mantissa;
	while (exp_i != 0)
	{
		i = 29;
		while (i >= 0)
		{
			(data->digits)[i] *= factor;
			while ((data->digits)[i] >= 100000000000000000UL)
			{
				(data->digits)[i] -= 100000000000000000UL;
				(data->digits)[i + 1]++;
			}
			i--;
		}
		exp_i += offset;
	}
}

static void	get_double_string(t_double_data *data)
{
	int			i;
	int			j;
	uint64_t	n;
	char		*str_it;

	i = 29;
	str_it = data->str;
	while (!data->digits[i] && (i >= 0))
		i--;
	str_it += sbase(data->digits[i], "0123456789", str_it);
	i--;
	while (i >= 0)
	{
		n = data->digits[i];
		j = 16;
		while (j >= 0)
		{
			str_it[j] = (n % 10) + '0';
			n /= 10;
			j--;
		}
		str_it += 17;
		i--;
	}
	*str_it = '\0';
}

void	set_float_data(t_double_data *data, double n)
{
	long long		temp;
	int				offset;
	int				factor;

	temp = *(long long *)&n;
	data->sign = (temp >> 63) & 0x1;
	data->exp = ((temp >> 52) & 0x7FF) - 1075;
	data->mantissa = (temp & 0xfffffffffffff) + 0x10000000000000;
	data->fractions = -data->exp;
	offset = -1;
	factor = 2;
	if (data->exp < 0)
	{
		offset = 1;
		factor = 5;
	}
	get_double_digits(data, offset, factor);
	get_double_string(data);
	if (data->exp > 0)
		data->fractions = 0;
	data->fraction_digits = data->fractions;
	if (data->fraction_digits > (int)ft_strlen(data->str))
		data->fraction_digits = (int)ft_strlen(data->str);
	data->whole_digits = ft_strlen(data->str) - data->fraction_digits;
}
