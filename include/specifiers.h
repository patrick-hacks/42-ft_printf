/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:32:31 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 04:24:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_H
# define SPECIFIERS_H

# include <stdarg.h>

# include "ft_vector.h"
# include "format_data.h"

# include "specifiers_decimal.h"
# include "specifiers_error.h"

typedef void (*t_specifier_function)(t_vector *buffer, t_format_data *data, va_list args);

#endif // SPECIFIERS_H
