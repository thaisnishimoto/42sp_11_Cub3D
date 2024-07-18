/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:47:21 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 14:42:00 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(mlx_image_t *img, t_vector *pos, size_t size, int color)
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
	t_vector	minimap;
	t_vector	draw_pos;
	int	scale;

	if (game->map.layout_rows > game->map.layout_columns)
		scale = MINI_HEIGHT / game->map.layout_rows;
	else
		scale = MINI_WIDTH / game->map.layout_columns;
	game->minimap_img = mlx_new_image(game->mlx, MINI_WIDTH, MINI_HEIGHT);
	if (!game->minimap_img)
        	handle_error("Minimap image creation failed", game, 1);
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
	if (mlx_image_to_window(game->mlx, game->minimap_img, scale, scale) < 0)
        	handle_error("Minimap image render failed", game, 0);
	game->minimap_img->instances->z = 3;
}
