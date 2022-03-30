/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_helper.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 05:49:20 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 06:13:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_HELPER_H
# define SPECIFIER_HELPER_H

typedef struct s_vector t_vector;
typedef struct s_subspecifiers t_subspecifiers;

#include <stdint.h>
#include <stdarg.h>

typedef struct s_nbr {
	long long	n;
	char				sign;
}						t_nbr;

char				get_sign(t_subspecifiers *data, int sign);
int					add_nbr(t_vector *buffer, t_subspecifiers *data,
						char *base, t_nbr nbr);

int			sbase(unsigned long long nbr, char *base, char *output);
unsigned long long	get_with_length_unsigned(uint8_t *flags, va_list args);
unsigned long long	get_with_length_signed(uint8_t *flags, va_list args);

#endif // SPECIFIER_HELPER_H
