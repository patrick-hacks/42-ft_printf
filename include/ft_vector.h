/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:31:33 by pfuchs            #+#    #+#             */
/*   Updated: 2022/04/03 10:52:11 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

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
