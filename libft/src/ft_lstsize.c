/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:21:07 by mchamma           #+#    #+#             */
/*   Updated: 2024/02/15 15:30:55 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Counts the number of nodes in the list

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}

// #include<stdio.h>

// int	main(void)
// {
// 	int 	content[] = {5, 4, 2, 10};
// 	t_list	*new_node;
// 	t_list	*lst;
// 	t_list	*next_node;

// 	lst = NULL;

// 	new_node = ft_lstnew(&content[0]);
// 	ft_lstadd_front(&lst, new_node);
// 	new_node = ft_lstnew(&content[1]);
// 	ft_lstadd_front(&lst, new_node);
// 	new_node = ft_lstnew(&content[2]);
// 	ft_lstadd_front(&lst, new_node);
// 	new_node = ft_lstnew(&content[3]);
// 	ft_lstadd_front(&lst, new_node);

// 	printf("%d\n", ft_lstsize(lst));

// 	while (lst != NULL)
// 	{
// 		printf("%d ", *(int *)lst->content);
// 		next_node = lst -> next;
// 		free(lst);
// 		lst = next_node;
// 	}

// 	return (0);
// }
