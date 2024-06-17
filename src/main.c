/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/17 17:15:03 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//static void error(void)
//{
//	puts(mlx_strerror(mlx_errno));
//	exit(EXIT_FAILURE);
//}

void	handle_error(char *msg, int errno_set)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (errno_set)
	{
		perror(msg);
		exit(EXIT_FAILURE);
	}
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	game;

	(void)argc;
	game.map.path = argv[1];
//	validate_map();
	parse_map(&game);
//	int i = 0;
//	while (game.map.content[i])
//	{
//		printf("%s", game.map.content[i]);
//		i++;
//	}
//	printf("\n%s", game.map.north_texture_path);
//	printf("\n%s", game.map.south_texture_path);
//	printf("\n%s", game.map.west_texture_path);
//	printf("\n%s", game.map.east_texture_path);
//	printf("\n%x", game.map.floor_color);
//	printf("\n%x", game.map.ceiling_color);
//	// Start mlx
//	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
//	if (!mlx)
//        error();
//
//	// Create a new image
//	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
//	if (!img)
//		error();
//
//	// Set every pixel to white
//	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));
//
//	// Display an instance of the image
//	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
//        error();
//
//	// Modify the x & y position of an already existing instance.
//	img->instances[0].x += 5;
//	img->instances[0].y += 5;
//
//	mlx_loop(mlx);
//
//	// Optional, terminate will clean up any leftovers, this is just to demonstrate.
//	mlx_delete_image(mlx, img);
//	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
