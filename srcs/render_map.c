/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:21:25 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/01 00:53:57 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	create_window(t_prog *mlx)
{
	int		fd;
	char	*line;

	mlx->map_width = 0;
	mlx->map_height = 0;
	fd = open(mlx->map_path, O_RDONLY);
	line = get_next_line(fd);
	mlx->map_width = ft_strlen(line) - 1;
	close(fd);
	fd = open(mlx->map_path, O_RDONLY);
	while (get_next_line(fd))
		mlx->map_height++;
	close(fd);
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_width * 32,
			mlx->map_height * 32, "so_long");
}

void	init_img(t_prog *mlx)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	width = 32;
	height = 32;
	mlx->img_path[0] = "img/floor.xpm";
	mlx->img_path[1] = "img/wall.xpm";
	mlx->img_path[2] = "img/exit.xpm";
	mlx->img_path[3] = "img/collectible.xpm";
	mlx->img_path[4] = "img/player_right.xpm";
	mlx->img_path[5] = "img/player_left.xpm";
	mlx->img_path[6] = "img/player_down.xpm";
	mlx->img_path[7] = "img/player_up.xpm";
	while (i < 8)
	{
		mlx->img_ptr[i] = mlx_xpm_file_to_image(mlx->mlx, mlx->img_path[i],
				&width, &height);
		i++;
	}
}

void	store_map(t_prog *mlx)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(mlx->map_path, O_RDONLY);
	while (i <= mlx->map_height)
	{
		mlx->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	render_player(t_prog *mlx, int i, int j)
{
	mlx->player_x = i;
	mlx->player_y = j;
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		mlx->img_ptr[4], i * 32, j * 32);
}

void	render_map(t_prog *mlx, int j, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (i <= mlx->map_width && line[i] != '\0')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_ptr[1], i * 32, j * 32);
		else if (line[i] == '0')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_ptr[0], i * 32, j * 32);
		else if (line[i] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_ptr[3], i * 32, j * 32);
		else if (line[i] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_ptr[2], i * 32, j * 32);
		else if (line[i] == 'P')
			render_player(&*mlx, i, j);
		i++;
	}
}
