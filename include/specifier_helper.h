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

char		get_sign(t_subspecifiers *data, int sign);
int			s_long_long(t_vector *buffer, t_subspecifiers *data,
	unsigned long long n, int sign);
int			sbase(unsigned long long nbr, char *base, char *output);

#endif // SPECIFIER_HELPER_H
