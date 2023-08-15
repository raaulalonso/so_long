/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:16:06 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/15 20:43:38 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft2_strcpy(t_prog *mlx, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	mlx->map_path = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != '\0')
	{
		mlx->map_path[i] = str[i];
		i++;
	}
	mlx->map_path[i] = '\0';
}

void	exit_game(t_prog *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	inicialize_var(t_prog *mlx)
{
	mlx->num_players = 0;
	mlx->num_exits = 0;
	mlx->num_collect = 0;
	mlx->collect_taken = 0;
}

int	main(int argc, char **argv)
{
	t_prog		mlx;
	int			j;
	int			fd;

	j = 0;
	if (argc != 2)
	{
		printf("Error\n");
		exit(0);
	}
	ft2_strcpy(&mlx, argv[1]);
	mlx.mlx = mlx_init();
	create_window(&mlx);
	init_img(&mlx);
	fd = open(mlx.map_path, O_RDONLY);
	while (j < mlx.map_height)
	{
		render_map(&mlx, j, fd);
		j++;
	}
	close(fd);
	store_map(&mlx);
	mlx_hook(mlx.win, 2, 0, press_key, &mlx);
	mlx_loop(mlx.mlx);
}
