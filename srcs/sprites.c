/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 23:28:53 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/25 19:29:15 by raalonso         ###   ########.fr       */
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
	mlx->img_path[9] = "textures/collect_2.xpm";
	mlx->img_path[10] = "textures/collect_3.xpm";
	mlx->img_path[11] = "textures/collect_4.xpm";
	mlx->img_path[12] = "textures/collect_5.xpm";
	mlx->img_path[13] = "textures/collect_6.xpm";
	mlx->img_path[14] = "textures/collect_7.xpm";
	mlx->img_path[15] = "textures/collect_8.xpm";
	while (i < 16)
	{
		mlx->img_ptr[i] = mlx_xpm_file_to_image(mlx->mlx, mlx->img_path[i],
				&width, &height);
		i++;
	}
}

void	check_delay(int *k, int *delay)
{
	if (*k == 15 && *delay == 25)
	{
		*k = 8;
		*delay = 0;
	}
	else if (*delay == 25)
	{
		*k = *k + 1;
		*delay = 0;
	}
}

int	animate(t_prog *mlx)
{
	int			i;
	int			j;
	static int	k = 8;
	static int	delay = 0;

	i = 0;
	j = 0;
	check_delay(&k, &delay);
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
	delay++;
	return (0);
}
