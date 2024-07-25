/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:31:38 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/23 11:31:41 by mchamma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_empty_line(char *line)
{
	int	is_empty;
	int	i;

	is_empty = 1;
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\v' && line[i] != '\f' && line[i] != '\r')
			is_empty = 0;
		i++;
	}
	return (is_empty);
}

void	replace_char(char *str, char old, char new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == old)
			str[i] = new;
		i++;
	}
}
