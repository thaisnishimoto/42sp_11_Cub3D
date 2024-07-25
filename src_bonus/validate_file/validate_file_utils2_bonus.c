/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file_utils2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchamma <mchamma@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 10:53:11 by mchamma           #+#    #+#             */
/*   Updated: 2024/07/25 11:35:09 by tmina-ni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	print_player(int *player)
{
	ft_printf("Player Qty: %i\n", player[0]);
	ft_printf("Player Direction: %c\n", player[3]);
	ft_printf("Player Coord: %i,", player[1]);
	ft_printf("%i\n", player[2]);
}

// for whole file, start = 0;
// only for map, start = 6;

void	print_file(char **file, int start)
{
	int	i;

	i = start;
	while (file[i])
	{
		ft_printf("%s\n", file[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_count(int *arr)
{
	ft_printf("NO: %i\n", arr[0]);
	ft_printf("SO: %i\n", arr[1]);
	ft_printf("EA: %i\n", arr[2]);
	ft_printf("WE: %i\n", arr[3]);
	ft_printf("F: %i\n", arr[4]);
	ft_printf("C: %i\n", arr[5]);
	ft_printf("MAP: %i\n", arr[6]);
	ft_printf("Empty: %i\n", arr[7]);
	ft_printf("Else: %i\n", arr[8]);
	ft_printf("Empty AM: %i\n", arr[9]);
	ft_printf("Content AM: %i\n", arr[10]);
	ft_printf("\n");
}
