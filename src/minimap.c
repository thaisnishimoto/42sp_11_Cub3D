/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/27 22:19:38 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_tile(mlx_image_t *img, t_coord *pos, size_t size, int color)
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

void	draw_minimap(t_data *game)
{
	t_coord	minimap;
	t_coord	draw_pos;
	int	scale;

	if (game->map.layout_rows > game->map.layout_columns)
		scale = MINI_HEIGHT / game->map.layout_rows;
	else
		scale = MINI_WIDTH / game->map.layout_columns;
	game->minimap_img = mlx_new_image(game->screen, MINI_WIDTH, MINI_HEIGHT);
	if (!game->minimap_img)
        	handle_error("Minimap image creation failed.", 0);
	minimap.y = 0;
	while (game->map.layout[(int)minimap.y])
	{
		minimap.x = 0;
		while (game->map.layout[(int)minimap.y][(int)minimap.x] != '\n')
		{
			draw_pos.x = minimap.x * scale;
			draw_pos.y = minimap.y * scale;
			if (game->map.layout[(int)minimap.y][(int)minimap.x] == '1')
				draw_tile(game->minimap_img, &draw_pos, scale, 0x00000080);
			else if (game->map.layout[(int)minimap.y][(int)minimap.x] == ' ')
				draw_tile(game->minimap_img, &draw_pos, scale, 0xFFFFFF00);
			else
				draw_tile(game->minimap_img, &draw_pos, scale, 0xFFFFFF80);
			minimap.x++;
		}
		minimap.y++;
	}
	if (mlx_image_to_window(game->screen, game->minimap_img, scale, scale) < 0)
        	handle_error("Minimap image render failed.", 0);
}

void	render_player(void *param)
{
	t_data	*game;
	t_coord	draw_pos;
	int	scale;

	game = param;
	if (game->player_img)
	{
		mlx_delete_image(game->screen, game->player_img);
	}
	if (game->map.layout_rows > game->map.layout_columns)
		scale = MINI_HEIGHT / game->map.layout_rows;
	else
		scale = MINI_WIDTH / game->map.layout_columns;
	game->player_img = mlx_new_image(game->screen, MINI_WIDTH, MINI_HEIGHT);
	if (!game->player_img)
		handle_error("Player image creation failed.", 0);
	draw_pos.x = game->player.x * scale;
	draw_pos.y = game->player.y * scale;
	draw_tile(game->player_img, &draw_pos, scale, 0x00FF00FF);
	draw_line(game, &game->player, scale);
	if (mlx_image_to_window(game->screen, game->player_img, scale, scale) < 0)
		handle_error("Player image render failed.", 0);
}

void	draw_line(t_data *game, t_coord *point1, int scale)
{
	int	delta_x;
	int	delta_y;
	t_coord	point2;
	int	steps;
	float	x_increment;
	float	y_increment;
	float	x;
	float	y;

	if (game->dir.x == 0 && game->dir.y == 1)
	{
		point2.x = point1->x;
		point2.y = game->map.layout_rows;
	}
	else if (game->dir.x == 0 && game->dir.y == -1)
	{
		point2.x = point1->x;
		point2.y = 0;
	}
	else if (game->dir.x == 1 && game->dir.y == 0)
	{
		point2.x = game->map.layout_columns - 1;
		point2.y = point1->y;
	}
	else if (game->dir.x == -1 && game->dir.y == 0)
	{
		point2.x = 0;
		point2.y = point1->y;
	}
	delta_x = point2.x - point1->x;
	delta_y = point2.y - point1->y;
	if (abs(delta_x) > abs(delta_y))
		steps = abs(delta_x);
	else
		steps = abs(delta_y);
	x_increment = (float)delta_x / steps;
	y_increment = (float)delta_y / steps;
	x = point1->x;
	y = point1->y;
	for (int i = 0; i <= steps; i++)
	{
		mlx_put_pixel(game->player_img, (int)x * scale, (int)y * scale, 0x00FF00FF);
		x += x_increment;
		y += y_increment;
	}
}
