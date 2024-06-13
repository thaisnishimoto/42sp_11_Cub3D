/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:24:07 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/12 23:43:12 by tmina-ni         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080

/*Structs*/
typedef struct s_map
{
	char	*path;
	int	file_rows;
	char	**file_content;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	int	*floor_color;
	int	*ceiling_color;
}	t_map;

typedef struct s_data
{
	t_map	map;
	
}	t_data;

#endif
