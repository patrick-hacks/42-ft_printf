/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_double_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:30:51 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/01 13:20:46 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_helper_float.h"
#include "specifier_helper.h"

#include "libft.h"

static void	get_double_digits(t_double_data *data, int offset, int factor)
{
	int	i;
	int exp_i;

	exp_i = data->exp;
	ft_memset(data->digits, 0, 20 * 8);
	(data->digits)[0] = data->mantissa;
	while (exp_i != 0)
	{
		i = 19;
		while (i >= 0)
		{
			(data->digits)[i] *= factor;
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

static void	get_double_string(t_double_data *data)
{
	int	i;
	int	str_it;

	i = 19;
	str_it = 0;
	while (i >= 0)
	{
		if (data->digits[i])
			str_it += sbase(data->digits[i], "0123456789", (data->str) + str_it);
		i--;
	}
	//TODO ADD DECIMAL HERE
	(data->str)[str_it] = '\0';
}

void	set_double_data(t_double_data *data, double n)
{
	long long		temp;
	int				offset;
	int				factor;

	temp = *(long long *)&n;
	data->sign = (temp >> 63) & 0x1;
	data->exp = ((temp >> 52) & 0x7FF) - 1075;
	data->mantissa = (temp & 	0xfffffffffffff) + 0x10000000000000;
	offset = -1;
	factor = 2;
	if (data->exp < 0)
	{
		offset = 1;
		factor = 5;
	}
	get_double_digits(data, offset, factor);
	get_double_string(data);
}
