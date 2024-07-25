/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:50:26 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/24 01:06:51 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	north_initial_setup(t_data *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	game->map.layout[y][x] = '0';
	game->dir.x = 0;
	game->dir.y = -1;
	game->plane.x = 0.66;
	game->plane.y = 0;
}

static void	south_initial_setup(t_data *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	game->map.layout[y][x] = '0';
	game->dir.x = 0;
	game->dir.y = 1;
	game->plane.x = -0.66;
	game->plane.y = 0;
}

static void	east_initial_setup(t_data *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	game->map.layout[y][x] = '0';
	game->dir.x = 1;
	game->dir.y = 0;
	game->plane.x = 0;
	game->plane.y = 0.66;
}

static void	west_initial_setup(t_data *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	game->map.layout[y][x] = '0';
	game->dir.x = -1;
	game->dir.y = 0;
	game->plane.x = 0;
	game->plane.y = -0.66;
}

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
				north_initial_setup(game, x, y);
			else if (game->map.layout[y][x] == 'S')
				south_initial_setup(game, x, y);
			else if (game->map.layout[y][x] == 'E')
				east_initial_setup(game, x, y);
			else if (game->map.layout[y][x] == 'W')
				west_initial_setup(game, x, y);
			x++;
		}
		y++;
	}
}
