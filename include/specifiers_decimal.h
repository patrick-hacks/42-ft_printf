/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_decimal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:02:05 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 04:23:38 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_DECIMAL_H
# define SPECIFIERS_DECIMAL_H

# include <stdarg.h>

# include "ft_vector.h"
# include "format_data.h"

void	signed_integer(t_vector *buffer, t_format_data *data, va_list args);
void	unsigned_integer(t_vector *buffer, t_format_data *data, va_list args);
void	unsigned_long_long(t_vector *buffer, t_format_data *data, va_list args);

#endif // SPECIFIERS_DECIMAL_H
