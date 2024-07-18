/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:12:10 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/18 12:47:15 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_deltas(t_dda *ray)
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

void	calculate_ray_initial_dist_to_sides(t_data *game, t_dda *ray)
{
	ray->map.x = floor(game->player.x);
	ray->map.y = floor(game->player.y);
	if (ray->dir.x < 0)
		ray->dist_side.x = (game->player.x - ray->map.x) * ray->delta_dist.x;
	else
		ray->dist_side.x = (ray->map.x + 1.0 - game->player.x) * ray->delta_dist.x;
	if (ray->dir.y < 0)
		ray->dist_side.y = (game->player.y - ray->map.y) * ray->delta_dist.y;
	else
		ray->dist_side.y = (ray->map.y + 1.0 - game->player.y) * ray->delta_dist.y;
}

int	set_step_increment_direction(float pos)
{
	if (pos < 0)
		return (-1);
	else
		return (1);
}

void	calculate_ray_dist_to_wall(t_data *game, t_dda *ray)
{
	while (game->map.layout[(int)ray->map.y][(int)ray->map.x] != '1')
	{
		if (ray->dist_side.x < ray->dist_side.y)
		{
			ray->dist_side.x += ray->delta_dist.x;
			ray->map.x += ray->step_x;
			ray->hit_side = 0;
		}
		else
		{
			ray->dist_side.y += ray->delta_dist.y;
			ray->map.y += ray->step_y;
			ray->hit_side = 1;
		}
	}
	if (ray->hit_side == 0)
		ray->perp_dist = ray->dist_side.x - ray->delta_dist.x;
	else
		ray->perp_dist = ray->dist_side.y - ray->delta_dist.y;
}

void	update_fps(t_data *game)
{
	char	*fps;
	char	*fps_str;
	static int	i;
	static mlx_image_t	*fps_img;

	game->frame_time = game->mlx->delta_time;
	if (i++ % 15 == 0)
	{
		fps = ft_itoa(1 / game->frame_time);
		fps_str = ft_strjoin("FPS: ", fps);
		free(fps);
		if (fps_img)
			mlx_delete_image(game->mlx, fps_img);
		fps_img = mlx_put_string(game->mlx, fps_str, WIDTH - 75, HEIGHT - 20);
		fps_img->instances->z = 6;
		free(fps_str);
	}
}

void	raycast(void *param)
{
	t_data	*game;
	t_dda	ray;

	game = param;
	update_fps(game);
	if (game->wall_img)
		mlx_delete_image(game->mlx, game->wall_img);
	game->wall_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->wall_img)
        	handle_error("Wall image creation failed", game, 0);
	ray.pixel_x = 0;
	while (ray.pixel_x < WIDTH)
	{
		ray.plane_ratio = 2 * ray.pixel_x / (float)WIDTH - 1;	
		ray.dir.x = game->dir.x + (game->plane.x * ray.plane_ratio);
		ray.dir.y = game->dir.y + (game->plane.y * ray.plane_ratio);
		ray.step_x = set_step_increment_direction(ray.dir.x);
		ray.step_y = set_step_increment_direction(ray.dir.y);
		calculate_ray_deltas(&ray);
		calculate_ray_initial_dist_to_sides(game, &ray);
		calculate_ray_dist_to_wall(game, &ray);
		//draw fov current ray
		render_wall_tex_to_screen(game, &ray);
		ray.pixel_x++;
	}
	if (mlx_image_to_window(game->mlx, game->wall_img, 0, 0) < 0)
        	handle_error("Wall image render failed", game, 0);
	game->wall_img->instances->z = 2;
//	mlx_set_instance_depth(game->wall_img->instances, 2);
}
