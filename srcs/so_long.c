/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:16:06 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/11 09:35:09 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	main(int argc, char **argv)
{
	t_prog		mlx;

	if (argc != 2)
	{
		printf("Error\n");
		exit(0);
	}
	if (ft2_strcpy(&mlx, argv[1]) == 1)
		return (0);
	check_ber(argv[1]);
	mlx.mlx = mlx_init();
	create_window(&mlx);
	init_img(&mlx);
	render_loop(&mlx);
	store_map(&mlx);
	get_map(&mlx);
	mlx_hook(mlx.win, 2, 0, press_key, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_game, &mlx);
	mlx_loop_hook(mlx.mlx, animate, &mlx);
	mlx_loop(mlx.mlx);
}
