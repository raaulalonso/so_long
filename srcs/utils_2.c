/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:55:14 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/11 21:31:07 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

char	**read_map(t_prog *mlx, char **map)
{
	int	i;
	int	j;
	int	fd;

	i = 0;
	j = 0;
	fd = open(mlx->map_path, O_RDONLY);
	while (j < mlx->map_height)
	{
		while (i < mlx->map_width + 1)
		{
			read(fd, &map[j][i], 1);
			i++;
		}
		i = 0;
		j++;
	}
	close(fd);
	floodfill(map, &*mlx, mlx->player_x, mlx->player_y);
	return (map);
}

void	get_map(t_prog *mlx)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * mlx->map_height + 1);
	if (!map)
		exit_game(&*mlx, 1);
	while (i < mlx->map_height + 1)
	{
		map[i] = malloc(sizeof(char) * mlx->map_width + 2);
		if (!map[i])
			exit_game(&*mlx, 1);
		i++;
	}
	map = read_map(&*mlx, map);
	i = 0;
	while (++i <= mlx->map_height + 1)
		free(map[i - 1]);
	free(map);
	check_path(&*mlx);
}

void	check_path(t_prog *mlx)
{
	if (mlx->valid_c != mlx->num_collect)
	{
		ft_printf("Error_6 :No valid path for collectables/exit.");
		exit_game(&*mlx, 1);
	}
	if (mlx->valid_e != 1)
	{
		ft_printf("Error_6 :No valid path for collectables/exit.");
		exit_game(&*mlx, 1);
	}
}

void	floodfill(char **map, t_prog *mlx, int p_x, int p_y)
{
	if (map[p_y][p_x] == '1')
		return ;
	if (map[p_y][p_x] == 'C')
		mlx->valid_c++;
	if (map[p_y][p_x] == 'E')
	{
		mlx->valid_e++;
		map[p_y][p_x] = '1';
		return ;
	}
	map[p_y][p_x] = '1';
	floodfill(map, mlx, p_x + 1, p_y);
	floodfill(map, mlx, p_x - 1, p_y);
	floodfill(map, mlx, p_x, p_y + 1);
	floodfill(map, mlx, p_x, p_y - 1);
}

void	free_mem(t_prog *mlx)
{
	int	i;

	i = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	while (i < 9)
	{
		mlx_destroy_image(mlx->mlx, mlx->img_ptr[i]);
		mlx->img_ptr[i] = NULL;
		i++;
	}
	mlx->win = NULL;
}
