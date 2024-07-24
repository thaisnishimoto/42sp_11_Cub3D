/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:35:37 by mchamma           #+#    #+#             */
/*   Updated: 2024/03/31 13:24:10 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Frees the memory of the node’s content using the function ’del’ given
// as a parameter and free the node.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(del)(lst -> content);
	free (lst);
}

// void	del(void *content)
// {
// 	free(content);
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

// 	ft_lstdelone(nodex, del);

// 	printf("End: %p e Val: %d\n", nodex, *(int *)nodex->content);

// 	return (0);
// }
