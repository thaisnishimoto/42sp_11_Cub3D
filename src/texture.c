/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:22:20 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/10 17:11:22 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	choose_texture(t_data *game, t_dda *ray)
{
	if (ray->hit_side == 0)
	{
		if (ray->step_x > 0)
			ray->texture = game->map.east_texture;
		else
			ray->texture = game->map.west_texture;
	}
	else
	{
		if (ray->step_y > 0)
			ray->texture = game->map.south_texture;
		else
			ray->texture = game->map.north_texture;
	}
}

void	calculate_hitpoint_pos(t_data *game, t_dda *ray)
{
	float	wall_hit_x;

	if (ray->hit_side == 0)
		wall_hit_x = game->player.x + ray->perp_dist * ray->dir.x;
	else
		wall_hit_x = game->player.y + ray->perp_dist * ray->dir.y;
	wall_hit_x = -= floor(wall_hit_x);
	ray->tex.x = (int)(ray->texture.width * wall_hit_x);
//	if ((ray->hitside == 0 && ray->dir.x < 0) || (ray->hitside == 1 && ray->dir.y > 0))
//		ray->tex.x = ray->texture.width - ray->tex.x
}

void	render_wall_line_to_screen(t_data *game, t_dda *ray)
{
	int	wall_height;
	int	line_start;
	int	line_end;
	float	tex_step;
	int	y;

	wall_height = HEIGHT / ray->perp_dist;
	line_start = HEIGHT / 2 - wall_height / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = HEIGHT / 2 + wall_height / 2;
	if (line_end >= HEIGHT)
		line_end = HEIGHT - 1;
	tex_step = (float)game->texture.height / wall_height;
	ray->tex.y = (wall_height / 2 - HEIGHT / 2 + line_start) * tex_step;
	y = line_start;
	while (y < line_end)
	{
//		mlx_put_pixel(game->wall_img, ray->pixel_x, pixel_y, ray->color); 
		ray->tex_y += tex_step;
		if (ray->tex_y >= ray->texture.height)
			ray->tex_y = ray->texture.height - 1;
		y++;
	}
}

void	render_wall_tex_to_screen(t_data *game, t_dda *ray)
{
	choose_texture(game, ray);
	calculate_hitpoint_pos(game, ray);

}
