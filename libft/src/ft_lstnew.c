/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:02:55 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:30:29 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Returns a new node in the linked list

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

// #include<stdio.h>

// int	main(void)
// {
// 	int		content;
// 	t_list	*new_node;

// 	content = 2;
// 	new_node = ft_lstnew(&content);

// 	printf("%d\n", *(int *)new_node->content);
// 	free(new_node);

// 	return (0);
// }
