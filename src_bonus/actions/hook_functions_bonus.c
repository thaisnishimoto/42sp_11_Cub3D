/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:39 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:49:50 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	key_press(void *param)
{
	t_data	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		end_game(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_UP))
		move_player(game, SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		move_player(game, -SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		move_player_left(game, SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		move_player_right(game, SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		rotate_player(game, ROTATE_SPEED);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		rotate_player(game, -ROTATE_SPEED);
}

void	cursor_movement(double mouse_x, double mouse_y, void *param)
{
	t_data			*game;
	static float	old_x;

	(void)mouse_y;
	game = param;
	if (mouse_x - old_x > 0)
		rotate_player(game, ROTATE_SPEED);
	else if (mouse_x - old_x < 0)
		rotate_player(game, -ROTATE_SPEED);
	old_x = mouse_x;
}

void	mouse_click(void *param)
{
	t_data	*game;

	game = param;
	if (game->shoot || mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
		shoot_weapon(game);
}
