/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/25 17:01:08 by tmina-ni         ###   ########.fr       */
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
# define MINI_TILE_SIZE 5

/*Structs*/
typedef struct s_pos
{
	size_t	x;
	size_t	y;
}	t_pos;

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

typedef struct s_player
{
	int	pos_x;
	int	pos_y;
}	t_player;

typedef struct s_data
{
	t_map	map;
	mlx_t	*screen;
	mlx_image_t	*background_img;
	mlx_image_t	*minimap_img;
	
}	t_data;

/*Parse functions*/
void	parse_map(t_data *game);
void	get_textures(t_data *game);
void	get_background_colors(t_data *game);
void	get_map_layout(t_data *game);
char	*skip_spaces(char *str);

void	handle_error(char *msg, int errno_set);

/*Parse functions*/
void	init_game(t_data *game);
void	draw_minimap(t_data *game);
#endif
