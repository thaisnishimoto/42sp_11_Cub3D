/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 07:17:29 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 14:56:52 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	west_initial_setup(t_data *game)
{
	game->dir.x = -1;
	game->dir.y = 0;
	game->plane.x = 0;
	game->plane.y = -0.66;
}

static void	east_initial_setup(t_data *game)
{
	game->dir.x = 1;
	game->dir.y = 0;
	game->plane.x = 0;
	game->plane.y = 0.66;
}

static void	south_initial_setup(t_data *game)
{
	game->dir.x = 0;
	game->dir.y = 1;
	game->plane.x = -0.66;
	game->plane.y = 0;
}

static void	north_initial_setup(t_data *game)
{
	game->dir.x = 0;
	game->dir.y = -1;
	game->plane.x = 0.66;
	game->plane.y = 0;
}

void	get_player_pos(t_data *game, int *player)
{
	game->player.x = player[2] + 0.5;
	game->player.y = player[1] - 6 + 0.5;
	if (player[3] == 'N')
		north_initial_setup(game);
	else if (player[3] == 'S')
		south_initial_setup(game);
	else if (player[3] == 'E')
		east_initial_setup(game);
	else if (player[3] == 'W')
		west_initial_setup(game);
}
