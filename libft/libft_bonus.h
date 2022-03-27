/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuchs <pfuchs@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:46:58 by pfuchs            #+#    #+#             */
/*   Updated: 2022/03/22 20:23:48 by pfuchs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BONUS_H
# define LIBFT_BONUS_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Returns a freeable initialised link
t_list	*ft_lstnew(const void *content);
// Adds "new_node" at the beginning of the list
void	ft_lstadd_front(t_list **lst, t_list *new_node);
// Returns the number of nodes
int		ft_lstsize(t_list *lst);
// Returns the last node of the list
t_list	*ft_lstlast(t_list *lst);
// Adds "new_node" at the end of the list
void	ft_lstadd_back(t_list **lst, t_list *new_node);
// Calls function "del" on the content of "alst" and free the link
void	ft_lstdelone(t_list *lst, void (*del)(void *));
// Deletes and frees the given node and every successor of that node
void	ft_lstclear(t_list **lst, void (*del)(void *));
// Applies the function on the content of every node
void	ft_lstiter(t_list *lst, void (*f)(void *));
// Creates a new list by applying "f" to every element of "lst"
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
