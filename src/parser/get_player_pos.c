/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 12:57:01 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			if (game->map.layout[y][x] == 'N')
			{
				game->player.x = x;
				game->player.y = y;
				game->dir.x = 0;
				game->dir.y = -1;
				game->plane.x = 0.66;
				game->plane.y = 0;
				break ;
			}
			else if (game->map.layout[y][x] == 'S')
			{
				game->player.x = x;
				game->player.y = y;
				game->dir.x = 0;
				game->dir.y = 1;
				game->plane.x = -0.66;
				game->plane.y = 0;
				break ;
			}
			else if (game->map.layout[y][x] == 'E')
			{
				game->player.x = x;
				game->player.y = y;
				game->dir.x = 1;
				game->dir.y = 0;
				game->plane.x = 0;
				game->plane.y = -0.66;
				break ;
			}
			else if (game->map.layout[y][x] == 'W')
			{
				game->player.x = x;
				game->player.y = y;
				game->dir.x = -1;
				game->dir.y = 0;
				game->plane.x = 0;
				game->plane.y = 0.66;
				break ;
			}
			//replace player pos to 0?
			x++;
		}
		y++;
	}
	printf("player pos x: %d | y: %d\n", (int)game->player.x, (int)game->player.y);
}
