/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:40:55 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:30:18 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Iterates the list and applies the function f on the content of each node.
// Creates a new list resulting of the successive applications of the
// function ’f’.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	new_lst = NULL;
	new_node = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

// void	*ft_add_one(void *content)
// {
// 	int	*data;

// 	data = (int *)content;
// 	(*data)++;
// 	return (content);
// }

// void	ft_destroy(void *content)
// {
// 	free(content);
// }

// #include <stdio.h>

// int	main(void)
// {
// 	int		*content;
// 	t_list	*new_node;
// 	t_list	*lst;
// 	t_list	*new_lst;
// 	t_list	*next_node;

// 	lst = NULL;

// 	content = (int *)malloc(sizeof(int));
// 	content[0] = 10;
// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);
// 	printf("End: %p e Val: %d\n", new_node, *(int *)new_node->content);

// 	content = (int *)malloc(sizeof(int));
// 	content[0] = 20;
// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);
// 	printf("End: %p e Val: %d\n", new_node, *(int *)new_node->content);

// 	content = (int *)malloc(sizeof(int));
// 	content[0] = 30;
// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);
// 	printf("End: %p e Val: %d\n", new_node, *(int *)new_node->content);

// 	new_lst = ft_lstmap(lst, ft_add_one, ft_destroy);

// 	while (new_lst)
// 	{
// 		printf("End: %p e Val: %d\n", new_lst, *(int *)new_lst->content);
// 		next_node = new_lst -> next;
// 		free(new_lst);
// 		new_lst = next_node;
// 	}
// 	while (lst)
// 	{
// 		printf("End: %p e Val: %d\n", lst, *(int *)lst->content);
// 		next_node = lst -> next;
// 		free(lst->content);
// 		free(lst);
// 		lst = next_node;
// 	}

// 	return (0);
// }
