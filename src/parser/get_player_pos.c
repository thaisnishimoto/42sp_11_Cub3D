/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/26 15:50:23 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_player_pos(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.layout[y])
	{
		x = 0;
		while (game->map.layout[y][x])
		{
			if (game->map.layout[y][x] == 'N' || game->map.layout[y][x] == 'S'
			|| game->map.layout[y][x] == 'E' || game->map.layout[y][x] == 'W')
			{
				game->player.x = x;
				game->player.y = y;
				printf("player pos x: %d | y: %d\n", x, y);
				break ;
			}
			x++;
		}
		y++;
	}
}
