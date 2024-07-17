/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmina-ni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:46:22 by tmina-ni          #+#    #+#             */
/*   Updated: 2024/07/17 14:01:51 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_error(char *msg, t_data *game, int stage)
{
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	if (stage > 0)
		ft_free_matrix(game->map.content);
	exit(EXIT_FAILURE);
}

int	end_game(void *param)
{
	t_data	*game;

	game = param;
	mlx_close_window(game->screen);
	mlx_delete_image(game->screen, game->background_img);
	mlx_delete_image(game->screen, game->minimap_img);
	mlx_delete_image(game->screen, game->player_img);
	mlx_terminate(game->screen);
	ft_free_matrix(game->map.content);
	free(game);
//	mlx_delete_texture;
//	for handle_error call
//	if (game->config_stage < 4)
//		return (1);
	exit (EXIT_SUCCESS);
}
