/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:16:06 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/11 21:37:32 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if ((str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
			|| str[i - 4] != '.') || (i < 5))
	{
		ft_printf("Error_5 :Not a .ber file.\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_prog		mlx;

	if (argc != 2)
	{
		ft_printf("Error_7 :Should include only map path.\n");
		exit(0);
	}
	if (get_path(&mlx, argv[1]) == 1)
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
