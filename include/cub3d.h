/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/18 18:03:29 by tmina-ni         ###   ########.fr       */
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
# define WIDTH 640
# define HEIGHT 480

/*Structs*/
typedef struct s_map
{
	char	*path;
	int	rows;
	char	**content;
	char	*north_tex_path;
	char	*south_tex_path;
	char	*west_tex_path;
	char	*east_tex_path;
	uint32_t	floor_color;
	uint32_t	ceiling_color;
	char	**layout;
}	t_map;

typedef struct s_data
{
	t_map	map;
	
}	t_data;

/*Parse functions*/
void	parse_map(t_data *game);
void	get_textures(t_data *game);
void	get_background_colors(t_data *game);
void	get_map_layout(t_data *game);
char	*skip_spaces(char *str);

void	handle_error(char *msg, int errno_set);

#endif
