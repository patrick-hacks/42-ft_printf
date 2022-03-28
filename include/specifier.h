/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 00:23:22 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 04:30:39 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPECIFIER_H
# define SPECIFIER_H

# include <stdarg.h>

typedef struct s_vector t_vector;
typedef struct s_subspecifiers t_subspecifiers;

int	call_specifier_function(char spec, t_vector *buffer,
	t_subspecifiers *data, va_list args);

#endif // SPECIFIER_H
