/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:24:47 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 11:33:02 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_player(int *player, int i, int j, char **file)
{
	player[0]++;
	player[1] = i;
	player[2] = j;
	player[3] = file[i][j];
	file[i][j] = '0';
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	*load_player(char **file)
{
	int	*player;
	int	i;
	int	j;

	player = ft_calloc(20, sizeof(int));
	i = 6;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (is_player(file[i][j]))
				update_player(player, i, j, file);
			j++;
		}
		i++;
	}
	return (player);
}
