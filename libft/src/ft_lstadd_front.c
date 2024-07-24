/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 09:43:07 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:29:12 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Adds the node at the beginning of the list

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

// #include<stdio.h>

// int	main(void)
// {
// 	int 	content[] = {10, 2, 4, 5};
// 	t_list	*new_node;
// 	t_list	*lst;
// 	t_list	*next_node;

// 	lst = NULL;

// 	new_node = ft_lstnew(&content[3]);
// 	ft_lstadd_front(&lst, new_node);

// 	new_node = ft_lstnew(&content[2]);
// 	ft_lstadd_front(&lst, new_node);

// 	new_node = ft_lstnew(&content[1]);
// 	ft_lstadd_front(&lst, new_node);

// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_front(&lst, new_node);

// 	while (lst != NULL)
// 	{
// 		printf("%d ", *(int *)lst->content);
// 		next_node = lst -> next;
// 		free(lst);
// 		lst = next_node;
// 	}

// 	return (0);
// }
