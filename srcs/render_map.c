/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:21:25 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/11 20:19:09 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	create_window(t_prog *mlx)
{
	int		fd;
	char	*line;

	mlx->map_width = 0;
	mlx->map_height = 1;
	fd = open(mlx->map_path, O_RDONLY);
	if (fd < 0)
		error_msg(4, &*mlx);
	line = get_next_line(fd);
	mlx->map_width = ft_strlen(line) - 1;
	free(line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		free(line);
		mlx->map_height++;
	}
	mlx->map_height--;
	free(line);
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
	mlx->img_path[0] = "textures/floor.xpm";
	mlx->img_path[1] = "textures/wall.xpm";
	mlx->img_path[2] = "textures/exit.xpm";
	mlx->img_path[3] = "textures/open.xpm";
	mlx->img_path[4] = "textures/player_right.xpm";
	mlx->img_path[5] = "textures/player_left.xpm";
	mlx->img_path[6] = "textures/player_down.xpm";
	mlx->img_path[7] = "textures/player_up.xpm";
	mlx->img_path[8] = "textures/collect_1.xpm";
	while (i < 9)
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
	mlx->map = malloc(sizeof(char *) * mlx->map_height + 1);
	i = 0;
	fd = open(mlx->map_path, O_RDONLY);
	if (fd < 0)
		error_msg(4, &*mlx);
	while (i <= mlx->map_height)
	{
		mlx->map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	check_square(&*mlx);
	check_walls(&*mlx);
	check_lines(&*mlx);
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
				mlx->img_ptr[8], i * 32, j * 32);
		else if (line[i] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win,
				mlx->img_ptr[2], i * 32, j * 32);
		else if (line[i] == 'P')
			render_player(&*mlx, i, j);
		i++;
	}
	free(line);
}
