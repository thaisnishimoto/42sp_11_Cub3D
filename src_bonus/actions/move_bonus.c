/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:39 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 11:50:06 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_signal(float num)
{
	if (num < 0)
		return (-1);
	else
		return (1);
}

void	move_player(t_data *game, float speed)
{
	t_vector	velocity;
	t_coord		map_new;
	float		wall_offset;

	velocity.x = game->dir.x * speed * game->frame_time;
	velocity.y = game->dir.y * speed * game->frame_time;
	wall_offset = get_signal(velocity.x) * WALL_OFFSET;
	map_new.x = game->player.x + velocity.x + wall_offset;
	wall_offset = get_signal(velocity.y) * WALL_OFFSET;
	map_new.y = game->player.y + velocity.y + wall_offset;
	if (game->map.layout[(int)game->player.y][map_new.x] == '0')
		game->player.x += velocity.x;
	if (game->map.layout[map_new.y][(int)game->player.x] == '0')
		game->player.y += velocity.y;
}

void	move_player_left(t_data *game, float speed)
{
	t_vector	velocity;
	t_coord		map_new;
	float		wall_offset;

	velocity.x = game->dir.y * speed * game->frame_time;
	velocity.y = -game->dir.x * speed * game->frame_time;
	wall_offset = get_signal(velocity.x) * WALL_OFFSET;
	map_new.x = game->player.x + velocity.x + wall_offset;
	wall_offset = get_signal(velocity.y) * WALL_OFFSET;
	map_new.y = game->player.y + velocity.y + wall_offset;
	if (game->map.layout[(int)game->player.y][map_new.x] == '0')
		game->player.x += velocity.x;
	if (game->map.layout[map_new.y][(int)game->player.x] == '0')
		game->player.y += velocity.y;
}

void	move_player_right(t_data *game, float speed)
{
	t_vector	velocity;
	t_coord		map_new;
	float		wall_offset;

	velocity.x = -game->dir.y * speed * game->frame_time;
	velocity.y = game->dir.x * speed * game->frame_time;
	wall_offset = get_signal(velocity.x) * WALL_OFFSET;
	map_new.x = game->player.x + velocity.x + wall_offset;
	wall_offset = get_signal(velocity.y) * WALL_OFFSET;
	map_new.y = game->player.y + velocity.y + wall_offset;
	if (game->map.layout[(int)game->player.y][map_new.x] == '0')
		game->player.x += velocity.x;
	if (game->map.layout[map_new.y][(int)game->player.x] == '0')
		game->player.y += velocity.y;
}

void	rotate_player(t_data *game, float speed)
{
	float	old_x;

	old_x = game->dir.x;
	game->dir.x = game->dir.x * cos(speed * game->frame_time)
		- game->dir.y * sin(speed * game->frame_time);
	game->dir.y = old_x * sin(speed * game->frame_time)
		+ game->dir.y * cos(speed * game->frame_time);
	old_x = game->plane.x;
	game->plane.x = game->plane.x * cos(speed * game->frame_time)
		- game->plane.y * sin(speed * game->frame_time);
	game->plane.y = old_x * sin(speed * game->frame_time)
		+ game->plane.y * cos(speed * game->frame_time);
}
