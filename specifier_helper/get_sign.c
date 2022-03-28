/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 05:48:38 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 06:11:41 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subspecifier.h"

char	get_sign(t_subspecifiers *data, int sign)
{
	if (sign)
		return '-';
	if (data->flags['+'])
		return '+';
	if (data->flags[' '])
		return ' ';
	return '\0';
}
