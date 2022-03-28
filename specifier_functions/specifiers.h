/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:23:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 01:28:31 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_H
#define SPECIFIERS_H

#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifiers.h"

#define SPEC_F_ARGS t_vector *buffer, t_subspecifiers *data, va_list args

typedef void (*t_specifier_function)(SPEC_F_ARGS);

void	signed_integer(SPEC_F_ARGS);
void	unsigned_integer(SPEC_F_ARGS);
void	unsigned_long_long(SPEC_F_ARGS);
void	error(SPEC_F_ARGS);

#endif // SPECIFIERS_H
