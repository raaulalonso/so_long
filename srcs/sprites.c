/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:28:53 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/23 00:51:49 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	init_animate_images(t_prog *mlx)
{
	int	width;
	int	height;
	int	i;

	i = 9;
	width = 32;
	height = 32;
	mlx->img_path[9] = "img/collect_2.xpm";
	mlx->img_path[10] = "img/collect_3.xpm";
	mlx->img_path[11] = "img/collect_4.xpm";
	mlx->img_path[12] = "img/collect_5.xpm";
	while (i < 13)
	{
		mlx->img_ptr[i] = mlx_xpm_file_to_image(mlx->mlx, mlx->img_path[i],
				&width, &height);
		i++;
	}
}

void	animate(t_prog *mlx, int k)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	init_animate_images(&*mlx);
	while (j < mlx->map_height)
	{
		while (i < mlx->map_width)
		{
			if (mlx->map[j][i] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win,
					mlx->img_ptr[k], i * 32, j * 32);
			i++;
		}
		i = 0;
		j++;
	}
}
