/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:27:01 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/29 09:34:38 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

#include <stdlib.h>

#include "libft.h"

int	ft_vector_init(t_vector *vector, int data_size)
{
	vector->data = malloc(data_size);
	if (!vector->data)
		return (1);
	vector->data_size = data_size;
	vector->size = 0;
	return (0);
}

int	ft_vector_set_data_size(t_vector *vector, int data_size)
{
	void	*new_data;

	if (data_size < vector->size)
		return (-1);
	new_data = malloc(data_size);
	if (!new_data)
		return (-1);
	ft_memcpy(new_data, vector->data, vector->size);
	free(vector->data);
	vector->data = new_data;
	vector->data_size = data_size;
	return (0);
}

int	ft_vector_push_back(t_vector *vector, const void *data, int size)
{
	if (vector->data_size - vector->size - size < 0)
	{
		if (ft_vector_set_data_size(vector, 100 + vector->size + size))
			return (-1);
	}
	ft_memcpy(vector->data + vector->size, data, size);
	vector->size += size;
	return (0);
}

int	ft_vector_pad_back(t_vector *vector, char pad, int size)
{
	if (size <= 0)
		return (0);
	if (vector->data_size - vector->size - size < 0)
	{
		if (ft_vector_set_data_size(vector, 100 + vector->size + size))
			return (-1);
	}
	ft_memset(vector->data + vector->size, pad, size);
	vector->size += size;
	return (0);
}

void	ft_vector_free(t_vector *vector)
{
	free(vector->data);
	vector->data = NULL;
	vector->data_size = 0;
	vector->size = 0;
}
