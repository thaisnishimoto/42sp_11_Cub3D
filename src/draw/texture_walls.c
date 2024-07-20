/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:22:20 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/20 00:10:57 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	choose_texture(t_data *game, t_dda *ray)
{
	if (ray->hit_side == 0)
	{
		if (ray->step_x > 0)
			ray->texture = game->map.east_tex;
		else
			ray->texture = game->map.west_tex;
	}
	else
	{
		if (ray->step_y > 0)
			ray->texture = game->map.south_tex;
		else
			ray->texture = game->map.north_tex;
	}
}

void	calculate_hitpoint_pos(t_data *game, t_dda *ray)
{
	float	wall_hit_x;

	if (ray->hit_side == 0)
		wall_hit_x = game->player.y + ray->perp_dist * ray->dir.y;
	else
		wall_hit_x = game->player.x + ray->perp_dist * ray->dir.x;
	wall_hit_x -= floor(wall_hit_x);
	ray->tex.x = (int)(ray->texture->width * wall_hit_x);
	if ((ray->hit_side == 0 && ray->dir.x < 0) || (ray->hit_side == 1 && ray->dir.y > 0))
		ray->tex.x = ray->texture->width - ray->tex.x;
}

//void	calculate_wall_measures(t_data *game, t_dda *ray)

int	get_color(t_dda *ray, int tex_y)
{
	uint8_t	*rgb;
	int	pixel_color;

	rgb = &ray->texture->pixels[(ray->texture->height * tex_y + (int)ray->tex.x) * ray->texture->bytes_per_pixel];
	pixel_color = rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3];
	return (pixel_color);
}

void	render_wall_line_to_screen(t_data *game, t_dda *ray)
{
	int	wall_height;
	int	line_start;
	int	line_end;
	float	tex_step;
	float	tex_pos;
	int	tex_y;
	int	y;

	wall_height = HEIGHT / ray->perp_dist;
	line_start = HEIGHT / 2 - wall_height / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = HEIGHT / 2 + wall_height / 2;
	if (line_end >= HEIGHT)
		line_end = HEIGHT - 1;
	tex_step = (float)ray->texture->height / wall_height;
	tex_pos = (wall_height / 2 - HEIGHT / 2 + line_start) * tex_step;
	y = line_start;
	while (y < line_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= (int)ray->texture->height - 1)
			tex_y = ray->texture->height - 1;
		ray->color = get_color(ray, tex_y);
//		mlx_put_pixel(game->wall_img, ray->pixel_x, y, ray->color); 
		mlx_put_pixel(game->playerview_img, ray->pixel_x, y, ray->color); 
		tex_pos += tex_step;
		y++;
	}
}

void	render_wall_tex_to_screen(t_data *game, t_dda *ray)
{
	choose_texture(game, ray);
	calculate_hitpoint_pos(game, ray);
	render_wall_line_to_screen(game, ray);
}
