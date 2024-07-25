/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 12:23:45 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static void	draw_miniplayer(t_data *game, int scale)
{
	t_coord	draw_pos;
	int		player_scale;

	player_scale = scale * 0.75;
	draw_pos.x = game->player.x * scale - player_scale / 2;
	draw_pos.y = game->player.y * scale - player_scale / 2;
	draw_tile(game->minimap_img, &draw_pos, player_scale, 0x00FF00FF);
}

static void	draw_layout(t_data *game, int scale)
{
	t_coord	minimap;
	t_coord	draw_pos;

	minimap.y = 0;
	while (game->map.layout[minimap.y])
	{
		minimap.x = 0;
		while (game->map.layout[minimap.y][minimap.x] != '\0')
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
	int		scale;

	game = param;
	if (game->map.layout_rows > game->map.layout_columns)
		scale = MINI_HEIGHT / game->map.layout_rows;
	else
		scale = MINI_WIDTH / game->map.layout_columns;
	draw_layout(game, scale);
	draw_miniplayer(game, scale);
}
