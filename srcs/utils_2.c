/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:55:14 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/10 21:16:25 by raalonso         ###   ########.fr       */
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
		printf("Error_4 :Not a .ber file.\n");
		exit(0);
	}
}

void	get_map(t_prog *mlx)
{
	char	**map;
	int		fd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * mlx->map_height + 1);
	while (i < mlx->map_height + 1)
	{
		map[i] = malloc(sizeof(char) * mlx->map_width + 2);
		i++;
	}
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
	check_path(&*mlx);
}

void	check_path(t_prog *mlx)
{
	if (mlx->valid_c != mlx->num_collect)
	{
		printf("Error_5 :No valid path for collectables/exit.");
		exit_game(&*mlx, 1);
	}
	if (mlx->valid_e != 1)
	{
		printf("Error_5 :No valid path for collectables/exit.");
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
		mlx->valid_e++;
	map[p_y][p_x] = '1';
	floodfill(map, mlx, p_x + 1, p_y);
	floodfill(map, mlx, p_x - 1, p_y);
	floodfill(map, mlx, p_x, p_y + 1);
	floodfill(map, mlx, p_x, p_y - 1);
}
