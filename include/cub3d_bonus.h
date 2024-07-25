/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/25 12:38:17 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H 

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
# define WALL_OFFSET 0.3
# define WEAPON_FRAMES 4
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
	char			*path;
	int				content_rows;
	char			**content;
	mlx_texture_t	*north_tex;
	mlx_texture_t	*south_tex;
	mlx_texture_t	*west_tex;
	mlx_texture_t	*east_tex;
	int32_t			floor_color;
	int32_t			ceiling_color;
	char			**layout;
	size_t			layout_rows;
	size_t			layout_columns;
}	t_map;

typedef struct s_wall
{
	int				height;
	int				line_start;
	int				line_end;
	mlx_texture_t	*texture;
	t_coord			tex;
	int				color;
}	t_wall;

typedef struct s_dda
{
	int			pixel_x;
	float		plane_ratio;
	t_vector	dir;
	t_vector	delta_dist;
	t_vector	dist_side;
	t_coord		map;
	t_coord		step;
	int			hit_side;
	float		perp_dist;
}	t_dda;

typedef struct s_data
{
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*minimap_img;
	mlx_image_t		*playerview_img;
	mlx_image_t		*wand_img[WEAPON_FRAMES];
	mlx_texture_t	*wand_tex[WEAPON_FRAMES];
	bool			shoot;
	t_vector		player;
	t_vector		dir;
	t_vector		plane;
	t_dda			ray;
	float			plane_ratio;
	float			frame_time;
}	t_data;

/*Validate functions*/
void	validate_file(int argc, char **argv);
int		validate_file_count(char *file_add);
int		validate_file_content(char *file_add);
int		validate_map_game(char *file_add);
char	**load_file(char *file_add);
int		file_rows(char *file_add);
int		*load_player(char **file);

/*Validate utils*/
int		is_empty_line(char *line);
void	replace_char(char *str, char old, char new);
void	error_file(int i);
int		hash_elem(char *line);

/*Parse functions*/
void	parse_map(t_data *game);
void	get_wall_textures(t_data *game);
void	get_weapon_textures(t_data *game);
void	get_background_colors(t_data *game);
void	get_map_layout(t_data *game);
void	get_player_pos(t_data *game, int *player);

/*Run game*/
void	run_game(t_data *game);
void	create_mlx_images(t_data *game);

/*Hook functions*/
void	key_press(void *param);
void	cursor_movement(double mouse_x, double mouse_y, void *param);
void	mouse_click(void *param);

/*Action functions*/
void	move_player(t_data *game, float speed);
void	move_player_left(t_data *game, float speed);
void	move_player_right(t_data *game, float speed);
void	rotate_player(t_data *game, float speed);
void	shoot_weapon(t_data *game);

/*Draw playerview functions*/
void	draw_playerview(void *param);
void	raycast_walls(t_data *game);
void	render_wall_tex_to_screen(t_data *game, t_dda *ray);

/*Draw minimap functions*/
void	draw_minimap(void *param);

/*End game*/
void	handle_error(char *msg, t_data *game, int stage);
void	end_game(void *param);

#endif
