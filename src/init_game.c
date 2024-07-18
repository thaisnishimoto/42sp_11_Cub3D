/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 15:23:11 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cursor_movement(double mouse_x, double mouse_y, void *param)
{
	t_data	*game;
	static float	old_x;

	(void)mouse_y;
	game = param;
	if (mouse_x - old_x > 0)
		rotate_player(game, ROTATE_SPEED);
	else if (mouse_x - old_x < 0)
		rotate_player(game, -ROTATE_SPEED);
	old_x = mouse_x;
}

void	init_game(t_data *game)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!game->mlx)
        	handle_error("Mlx init failed", game, 1);
	draw_background(game);
	draw_minimap(game);
	load_weapon_textures(game);
	mlx_close_hook(game->mlx, end_game, game);
	mlx_loop_hook(game->mlx, key_press, game);
	mlx_cursor_hook(game->mlx, cursor_movement, game);
	mlx_loop_hook(game->mlx, mouse_click, game);
	mlx_loop_hook(game->mlx, draw_miniplayer, game);
	mlx_loop_hook(game->mlx, raycast, game);
	mlx_loop(game->mlx);
}
