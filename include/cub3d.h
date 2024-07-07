/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/07 01:27:37 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H 

# include "MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

/*Macros*/
# define WIDTH 800
# define HEIGHT 600
# define MINI_WIDTH 200
# define MINI_HEIGHT 200
# define SPEED 3.0
# define ROTATE_SPEED 3.0

/*Structs*/
typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_map
{
	char	*path;
	int	content_rows;
	char	**content;
	char	*north_tex_path;
	char	*south_tex_path;
	char	*west_tex_path;
	char	*east_tex_path;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	char	**layout;
	size_t	layout_rows;
	size_t	layout_columns;
}	t_map;

typedef struct s_dda
{
	int	pixel_x;
	float	plane_ratio;
	t_vector	dir;
	t_vector	delta_dist;
	t_vector	dist_side;
	t_vector	map;
	int	step_x;
	int	step_y;
	int	hit_side;
	int	color;
	float	perp_dist;
}	t_dda;

typedef struct s_data
{
	t_map	map;
	mlx_t	*screen;
	mlx_image_t	*background_img;
	mlx_image_t	*minimap_img;
	mlx_image_t	*player_img;
	mlx_image_t	*wall_img;
	t_vector	player;
	t_vector	dir;
	t_vector	plane;
	t_dda	ray;
	float	plane_ratio;
	float	frame_time;
}	t_data;

/*Parse functions*/
void	parse_map(t_data *game);
void	get_textures(t_data *game);
void	get_background_colors(t_data *game);
void	get_map_layout(t_data *game);
void	get_player_pos(t_data *game);
char	*skip_spaces(char *str);

void	handle_error(char *msg, int errno_set);

/*Run game*/
void	init_game(t_data *game);
void	draw_minimap(t_data *game);

/*Hook functions*/
void	key_press(void *param);
int		end_game(void *param);
void	render_player(void *param);
void	draw_line(t_data *game, t_vector *point1, int scale);
void    raycast(void *param);

/*Move functions*/
void	rotate_player(t_data *game, float speed);

#endif
