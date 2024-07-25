/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_walls_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:22:20 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:51:15 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	choose_texture(t_data *game, t_dda *ray, t_wall *wall)
{
	if (ray->hit_side == 0)
	{
		if (ray->step.x > 0)
			wall->texture = game->map.east_tex;
		else
			wall->texture = game->map.west_tex;
	}
	else
	{
		if (ray->step.y > 0)
			wall->texture = game->map.south_tex;
		else
			wall->texture = game->map.north_tex;
	}
}

static void	calculate_hitpoint_x_pos(t_data *game, t_dda *ray, t_wall *wall)
{
	float	wall_hit_x;

	if (ray->hit_side == 0)
		wall_hit_x = game->player.y + ray->perp_dist * ray->dir.y;
	else
		wall_hit_x = game->player.x + ray->perp_dist * ray->dir.x;
	wall_hit_x -= floor(wall_hit_x);
	wall->tex.x = (int)(wall->texture->width * wall_hit_x);
	if ((ray->hit_side == 0 && ray->dir.x < 0)
		|| (ray->hit_side == 1 && ray->dir.y > 0))
		wall->tex.x = wall->texture->width - 1 - wall->tex.x;
}

static int	get_color(t_wall *wall)
{
	uint8_t	*rgb;
	int		texel_pos;
	int		pixel_color;

	texel_pos = wall->texture->height * wall->tex.y + wall->tex.x;
	texel_pos *= wall->texture->bytes_per_pixel;
	rgb = &wall->texture->pixels[texel_pos];
	pixel_color = rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | rgb[3];
	return (pixel_color);
}

static void	render_wall_line_to_screen(t_data *game, t_dda *ray, t_wall *wall)
{
	float	tex_step;
	float	tex_pos;
	int		pixel_y;

	wall->height = HEIGHT / ray->perp_dist;
	wall->line_start = HEIGHT / 2 - wall->height / 2;
	if (wall->line_start < 0)
		wall->line_start = 0;
	wall->line_end = HEIGHT / 2 + wall->height / 2;
	if (wall->line_end >= HEIGHT)
		wall->line_end = HEIGHT - 1;
	tex_step = (float)wall->texture->height / wall->height;
	tex_pos = (wall->height / 2 - HEIGHT / 2 + wall->line_start) * tex_step;
	pixel_y = wall->line_start;
	while (pixel_y < wall->line_end)
	{
		wall->tex.y = (int)tex_pos;
		if (wall->tex.y > (int)wall->texture->height - 1)
			wall->tex.y = wall->texture->height - 1;
		wall->color = get_color(wall);
		mlx_put_pixel(game->playerview_img, ray->pixel_x,
			pixel_y, wall->color);
		tex_pos += tex_step;
		pixel_y++;
	}
}

void	render_wall_tex_to_screen(t_data *game, t_dda *ray)
{
	t_wall	wall;

	choose_texture(game, ray, &wall);
	calculate_hitpoint_x_pos(game, ray, &wall);
	render_wall_line_to_screen(game, ray, &wall);
}
