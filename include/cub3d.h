/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/19 15:18:54 by tmina-ni         ###   ########.fr       */
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
# define WALL_OFFSET 0.25
# define WEAPON_FRAMES 5
# define REPEAT_FRAME 4

/*Structs*/
typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	char	*path;
	int	content_rows;
	char	**content;
	char	*north_tex_path;
	char	*south_tex_path;
	char	*west_tex_path;
	char	*east_tex_path;
	mlx_texture_t	*north_tex;
	mlx_texture_t	*south_tex;
	mlx_texture_t	*west_tex;
	mlx_texture_t	*east_tex;
	int32_t	floor_color;
	int32_t	ceiling_color;
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
	float	perp_dist;
	mlx_texture_t	*texture;
	t_vector	tex;
	int	color;
}	t_dda;

typedef struct s_data
{
	t_map	map;
	mlx_t	*mlx;
//	mlx_image_t	*back_img;
	mlx_image_t	*minimap_img;
//	mlx_image_t	*wall_img;
	mlx_image_t	*playerview_img;
	mlx_image_t	*wand_img[WEAPON_FRAMES];
	mlx_texture_t	*wand_tex[WEAPON_FRAMES];
	bool	shoot;
	t_vector	player;
	t_vector	dir;
	t_vector	plane;
	t_dda	ray;
	float	plane_ratio;
	float	frame_time;
}	t_data;

/*Parse functions*/
void	parse_map(t_data *game);
void	get_wall_textures(t_data *game);
void	get_weapon_textures(t_data *game);
void	get_background_colors(t_data *game);
void	get_map_layout(t_data *game);
void	get_player_pos(t_data *game);
char	*skip_spaces(char *str);

/*Run game*/
void	run_game(t_data *game);
void	create_mlx_images(t_data *game);
void	draw_background(t_data *game);
void	draw_minimap(void *param);
//void	draw_minimap(t_data *game);
//void	load_weapon_textures(t_data *game);

/*Draw functions*/
void	draw_miniplayer(t_data *game, int scale);
void	draw_line(t_data *game, t_vector *point1, int scale);
void    draw_tile(mlx_image_t *img, t_coord *pos, size_t size, int color);
void    raycast(void *param);

/*Texture functions*/
void	render_wall_tex_to_screen(t_data *game, t_dda *ray);

/*Control functions*/
void	key_press(void *param);
void	mouse_click(void *param);
void    cursor_movement(double mouse_x, double mouse_y, void *param);
void	rotate_player(t_data *game, float speed);
void	shoot_weapon(t_data *game);

/*End game*/
void	handle_error(char *msg, t_data *game, int stage);
void	end_game(void *param);

#endif
