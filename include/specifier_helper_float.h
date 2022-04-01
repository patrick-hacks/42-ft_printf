/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_helper_float.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:31:26 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/01 13:09:18 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_HELPER_FLOAT_H
# define SPECIFIER_HELPER_FLOAT_H

# include <stdint.h>

typedef struct s_double_data {
	int			sign;
	int			exp;
	uint64_t	mantissa;
	uint64_t	digits[20];
	char		str[310];
	int			decimals;
}	t_double_data;

void	set_double_data(t_double_data *data, double n);

#endif // SPECIFIER_HELPER_FLOAT_H
