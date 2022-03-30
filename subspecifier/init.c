/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 04:35:13 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/28 06:21:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "subspecifier.h"

#include "libft.h"

void	init_t_subspecifiers(t_subspecifiers *data)
{
	int	i;

	data->precision = -1;
	data->width = -1;
	i = 0;
	while (i < (int)sizeof(data->flags))
	{
		(data->flags)[i] = 0;
		i++;
	}
	i = 0;
}
