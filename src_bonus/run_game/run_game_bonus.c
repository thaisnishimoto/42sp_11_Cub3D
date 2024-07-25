/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 12:22:52 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	run_game(t_data *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D Bonus", false);
	if (!game->mlx)
		handle_error("Mlx init failed", game, 1);
	create_mlx_images(game);
	mlx_close_hook(game->mlx, end_game, game);
	mlx_loop_hook(game->mlx, key_press, game);
	mlx_cursor_hook(game->mlx, cursor_movement, game);
	mlx_loop_hook(game->mlx, mouse_click, game);
	mlx_loop_hook(game->mlx, draw_playerview, game);
	mlx_loop_hook(game->mlx, draw_minimap, game);
	mlx_loop(game->mlx);
}
