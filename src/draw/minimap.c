/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/20 00:06:55 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_tile(mlx_image_t *img, t_coord *pos, size_t size, int color)
{
	size_t	current_x;
	size_t	current_y;

	current_y = pos->y;
	while (current_y < (pos->y + size))
	{
		current_x = pos->x;
		while (current_x < (pos->x + size))
		{
			mlx_put_pixel(img, current_x, current_y, color); 
			current_x++;
		}
		current_y++;
	}
}

void    draw_miniplayer(t_data *game, int scale)
{
	t_coord	draw_pos;
	int	player_scale;

	player_scale = scale * 0.75;
	draw_pos.x = game->player.x * scale - player_scale / 2;
	draw_pos.y = game->player.y * scale - player_scale / 2;
//	mlx_put_pixel(game->player_img, draw_pos.x, draw_pos.y, 0x00FF00FF); 
	draw_tile(game->minimap_img, &draw_pos, player_scale, 0x00FF00FF);
//	draw_line(game, &game->player, scale);
}

void	draw_layout(t_data *game, int scale)
{
	t_coord	minimap;
	t_coord	draw_pos;

	minimap.y = 0;
	while (game->map.layout[minimap.y])
	{
		minimap.x = 0;
		//change to \0
		while (game->map.layout[minimap.y][minimap.x] != '\n')
		{
			draw_pos.x = minimap.x * scale;
			draw_pos.y = minimap.y * scale;
			if (game->map.layout[minimap.y][minimap.x] == '1')
				draw_tile(game->minimap_img, &draw_pos, scale, 0x00000080);
			else if (game->map.layout[minimap.y][minimap.x] == ' ')
				draw_tile(game->minimap_img, &draw_pos, scale, 0xFFFFFF00);
			else
				draw_tile(game->minimap_img, &draw_pos, scale, 0xFFFFFF80);
			minimap.x++;
		}
		minimap.y++;
	}
}

void	draw_minimap(void *param)
{
	t_data	*game;
	int	scale;

	game = param;
	if (game->map.layout_rows > game->map.layout_columns)
		scale = MINI_HEIGHT / game->map.layout_rows;
	else
		scale = MINI_WIDTH / game->map.layout_columns;
	draw_layout(game, scale);
	draw_miniplayer(game, scale);
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
