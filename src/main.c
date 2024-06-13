/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:38:58 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/06/13 18:25:29 by tmina-ni         ###   ########.fr       */
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

int	get_file_rows(t_data *game)
{
	int	fd;
	int	count;
	char	*line;

	fd = open(game->map.path, O_RDWR);
	if (fd == -1)
		handle_error("Open failed", 1);
	count = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
			count++;
		free(line);
		line = ft_get_next_line(fd);
	}
	if (close(fd) == -1)
		handle_error("Close failed", 1);
	return (count);
}

void	get_file_content(t_data *game)
{
	int	fd;
	int	i;
	char	*line;

	game->map.file_rows = get_file_rows(game);
	ft_printf("rows: %d\n", game->map.file_rows);
	fd = open(game->map.path, O_RDWR);
	if (fd == -1)
		handle_error("Open failed", 1);
	game->map.file_content = ft_calloc(game->map.file_rows + 1, sizeof(char *));
	i = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_strcmp(line, "\n"))
		{
			game->map.file_content[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	if (close(fd) == -1)
		handle_error("Close failed", 1);
}

//void	parse_map(t_data *game)
//{
//}
//
//void	get_textures(t_data *game)
//{
//
//}

int	main(int argc, char **argv)
{
	t_data	game;

	(void)argc;
	game.map.path = argv[1];
//	parse_map(&game);
	get_file_content(&game);
	int i = 0;
	while (game.map.file_content[i])
	{
		printf("%s", game.map.file_content[i]);
		i++;
	}
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
