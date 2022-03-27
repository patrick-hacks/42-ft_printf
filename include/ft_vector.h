/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:31:33 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/27 01:41:14 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector {
	void	*data;
	int		data_size;
	int		size;
}	t_vector;

int		ft_vector_init(t_vector *vector, int data_size);
void	ft_vector_free(t_vector *vector);
int		ft_vector_set_data_size(t_vector *vector, int data_size);
int		ft_vector_push_back(t_vector *vector, const void *data, int size);
int		ft_vector_pad_back(t_vector *vector, char pad, int size);

#endif
