/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_error.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 03:31:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 04:24:44 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIERS_ERROR_H
# define SPECIFIERS_ERROR_H

# include <stdarg.h>

# include "ft_vector.h"
# include "format_data.h"

void	error(t_vector *buffer, t_format_data *data, va_list args);

#endif // SPECIFIERS_ERROR_H
