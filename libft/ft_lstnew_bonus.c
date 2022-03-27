/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:20:00 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 20:18:52 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h" // t_list

#include <stddef.h> // NULL size_t
#include <stdlib.h> // malloc

// Returns a freeable initialised link
t_list	*ft_lstnew(void const *content)
{
	t_list	*my_list;

	my_list = malloc(sizeof(t_list));
	if (!my_list)
		return (NULL);
	my_list->content = (void *)content;
	my_list->next = NULL;
	return (my_list);
}
