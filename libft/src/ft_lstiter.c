/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 22:28:30 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:29:58 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Iterates the list and applies the function f on the content of each node.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		aux = (lst)->next;
		(f)((lst)-> content);
		lst = aux;
	}
}

// void	iter(void *content)
// {
// 	int	*data;

// 	data = (int *)content;
// 	(*data)++;
// }

// #include <stdio.h>

// int	main(void)
// {
// 	int		*content;
// 	t_list	*new_node;
// 	t_list	*lst;
// 	t_list	*nodex;

// 	lst = NULL;

// 	content = (int *)malloc(sizeof(int));
// 	content[0] = 10;
// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_back(&lst, new_node);
// 	printf("End: %p e Val: %d\n", new_node, *(int *)new_node->content);

// 	nodex = new_node;

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

// 	ft_lstiter(lst, iter);

// 	printf("End: %p e Val: %d\n", nodex, *(int *)nodex->content);

// 	return (0);
// }
