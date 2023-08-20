/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 22:53:18 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/19 23:14:09 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	error_msg(int type, t_prog *mlx)
{
	if (type == 1)
		printf("Error_1 :Invalid map, not surrounded by walls.\n");
	if (type == 2)
		printf("Error_1 :Invalid map, multiple/non players or exits.\n");
	if (type == 3)
		printf("Error_1 :Invalid map, invalid characters.\n");
	exit_game(&*mlx);
}

void	check_middle_walls(t_prog *mlx)
{
	int	i;

	i = 1;
	while (i < mlx->map_height - 1)
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][mlx->map_width - 1] != '1')
			error_msg(1, &*mlx);
		i++;
	}
}

void	check_walls(t_prog *mlx)
{
	int	i;

	i = 0;
	while (mlx->map[0][i] != '\0')
	{
		if (mlx->map[0][i] != '1' && mlx->map[0][i] != '\n')
			error_msg(1, &*mlx);
		i++;
	}
	i = 0;
	while (mlx->map[mlx->map_height - 1][i] != '\0')
	{
		if (mlx->map[mlx->map_height - 1][i]
				!= '1' && mlx->map[mlx->map_height - 1][i] != '\n')
			error_msg(1, &*mlx);
		i++;
	}
	check_middle_walls(&*mlx);
}

void	check_square(t_prog *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < mlx->map_height)
	{
		while (mlx->map[j][i] != '\n')
		{
			i++;
		}
		if (i != mlx->map_width)
			error_msg(1, &*mlx);
		i = 0;
		j++;
	}
}

void	check_lines(t_prog *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	inicialize_var(&*mlx);
	while (j < mlx->map_height)
	{
		while (mlx->map[j][i] != '\n')
		{
			if (mlx->map[j][i] == 'P')
				mlx->num_players++;
			else if (mlx->map[j][i] == 'E')
				store_exit(&*mlx, i, j);
			else if (mlx->map[j][i] == 'C')
				mlx->num_collect++;
			else if (mlx->map[j][i] != '1' && mlx->map[j][i] != '0')
				error_msg(3, &*mlx);
			i++;
		}
		i = 0;
		j++;
	}
	if (mlx->num_players != 1 || mlx->num_exits != 1)
		error_msg(2, &*mlx);
}
