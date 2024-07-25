/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_walls_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:12:10 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:51:00 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	set_step_increment_direction(float pos)
{
	if (pos < 0)
		return (-1);
	else
		return (1);
}

static void	calculate_ray_deltas(t_dda *ray)
{
	if (ray->dir.x == 0)
		ray->delta_dist.x = HUGE_VALF;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = HUGE_VALF;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	calculate_ray_initial_dist_to_sides(t_data *game, t_dda *ray)
{
	ray->map.x = game->player.x;
	ray->map.y = game->player.y;
	if (ray->dir.x < 0)
		ray->dist_side.x = (game->player.x - ray->map.x) * ray->delta_dist.x;
	else
	{
		ray->dist_side.x = (ray->map.x + 1.0 - game->player.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
		ray->dist_side.y = (game->player.y - ray->map.y) * ray->delta_dist.y;
	else
	{
		ray->dist_side.y = (ray->map.y + 1.0 - game->player.y)
			* ray->delta_dist.y;
	}
}

static void	calculate_ray_dist_to_wall(t_data *game, t_dda *ray)
{
	while (game->map.layout[ray->map.y][ray->map.x] != '1')
	{
		if (ray->dist_side.x < ray->dist_side.y)
		{
			ray->dist_side.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->hit_side = 0;
		}
		else
		{
			ray->dist_side.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->hit_side = 1;
		}
	}
	if (ray->hit_side == 0)
		ray->perp_dist = ray->dist_side.x - ray->delta_dist.x;
	else
		ray->perp_dist = ray->dist_side.y - ray->delta_dist.y;
}

void	raycast_walls(t_data *game)
{
	t_dda	ray;

	ray.pixel_x = 0;
	while (ray.pixel_x < WIDTH)
	{
		ray.plane_ratio = 2 * ray.pixel_x / (float)WIDTH - 1;
		ray.dir.x = game->dir.x + (game->plane.x * ray.plane_ratio);
		ray.dir.y = game->dir.y + (game->plane.y * ray.plane_ratio);
		ray.step.x = set_step_increment_direction(ray.dir.x);
		ray.step.y = set_step_increment_direction(ray.dir.y);
		calculate_ray_deltas(&ray);
		calculate_ray_initial_dist_to_sides(game, &ray);
		calculate_ray_dist_to_wall(game, &ray);
		render_wall_tex_to_screen(game, &ray);
		ray.pixel_x++;
	}
}
