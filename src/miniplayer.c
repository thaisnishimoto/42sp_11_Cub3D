/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 15:17:23 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_miniplayer(void *param)
{
	t_data	*game;
	t_vector	draw_pos;
	int	scale;

	game = param;
	if (game->player_img)
	{
		mlx_delete_image(game->mlx, game->player_img);
	}
	if (game->map.layout_rows > game->map.layout_columns)
		scale = MINI_HEIGHT / game->map.layout_rows;
	else
		scale = MINI_WIDTH / game->map.layout_columns;
	game->player_img = mlx_new_image(game->mlx, MINI_WIDTH, MINI_HEIGHT);
	if (!game->player_img)
		handle_error("Player image creation failed", game, 0);
	draw_pos.x = game->player.x * scale;
	draw_pos.y = game->player.y * scale;
//	mlx_put_pixel(game->player_img, draw_pos.x, draw_pos.y, 0x00FF00FF); 
	draw_tile(game->player_img, &draw_pos, scale, 0x00FF00FF);
//	draw_line(game, &game->player, scale);
	if (mlx_image_to_window(game->mlx, game->player_img, scale, scale) < 0)
		handle_error("Player image render failed", game, 0);
	game->player_img->instances->z = 4;
}

//void	draw_line(t_data *game, t_vector *point1, int scale)
//{
//	int	delta_x;
//	int	delta_y;
//	t_vector	point2;
//	int	steps;
//	float	x_increment;
//	float	y_increment;
//	float	x;
//	float	y;
//
//	if (game->dir.x == 0 && game->dir.y == 1)
//	{
//		point2.x = point1->x;
//		point2.y = game->map.layout_rows;
//	}
//	else if (game->dir.x == 0 && game->dir.y == -1)
//	{
//		point2.x = point1->x;
//		point2.y = 0;
//	}
//	else if (game->dir.x == 1 && game->dir.y == 0)
//	{
//		point2.x = game->map.layout_columns - 1;
//		point2.y = point1->y;
//	}
//	else if (game->dir.x == -1 && game->dir.y == 0)
//	{
//		point2.x = 0;
//		point2.y = point1->y;
//	}
//	delta_x = point2.x - point1->x;
//	delta_y = point2.y - point1->y;
//	if (abs(delta_x) > abs(delta_y))
//		steps = abs(delta_x);
//	else
//		steps = abs(delta_y);
//	x_increment = (float)delta_x / steps;
//	y_increment = (float)delta_y / steps;
//	x = point1->x;
//	y = point1->y;
//	for (int i = 0; i <= steps; i++)
//	{
//		mlx_put_pixel(game->player_img, (int)x * scale, (int)y * scale, 0x00FF00FF);
//		x += x_increment;
//		y += y_increment;
//	}
//}
