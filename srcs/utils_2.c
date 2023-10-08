/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:55:14 by raalonso          #+#    #+#             */
/*   Updated: 2023/10/05 12:35:47 by raalonso         ###   ########.fr       */
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
	fd = open(mlx->map_path, O_RDONLY);
	if (fd < 0)
		error_msg(4, &*mlx);
	while (i < mlx->map_height)
	{
		j = 0;
		while (j < mlx->map_width)
		{
			read(fd, &map[i][j], 1);
			j++;
		}
		i++;
	}
	map[i - 1][mlx->map_width] = '1';
	//i = 0;
	close(fd);
	/*while (i < mlx->map_height)
	{
		printf("\n%s\n", map[i]);
		i++;
	}*/
	//printf("%s", map[2]);
	floodfill(map, &*mlx, mlx->player_x + 1, mlx->player_y, 0, 0);
}

void	floodfill(char **map, t_prog *mlx, int p_x, int p_y, int *valid_c, int *valid_e)
{
	if (map[p_y][p_x] == 'C')
		valid_c++;
	if (map[p_y][p_x] == 'E')
		valid_e++;
	if (map[p_y][p_x] == '1')
		return ;

	map[p_y][p_x] = '1';
	floodfill(map, mlx, p_x + 1, p_y, valid_c, valid_e);
	floodfill(map, mlx, p_x - 1, p_y, valid_c, valid_e);
	floodfill(map, mlx, p_x, p_y + 1, valid_c, valid_e);
	floodfill(map, mlx, p_x, p_y - 1, valid_c, valid_e);
	
	if (*valid_c != mlx->num_collect || *valid_e != mlx->num_exits)
	{
		printf("Error_5: Map not valid.\n");
		exit(0);
	}
}
