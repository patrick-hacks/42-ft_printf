/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_percent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 06:58:38 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 06:59:53 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "specifier_functions.h"

#include <stdarg.h>

#include "ft_vector.h"
#include "subspecifier.h"

int	s_percent(t_vector *buffer, t_subspecifiers *data, va_list args)
{
	ft_vector_push_back(buffer, "%", 1);
	(void) data;
	(void) args;
	return (0);
}
