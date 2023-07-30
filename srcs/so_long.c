/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:16:06 by raalonso          #+#    #+#             */
/*   Updated: 2023/07/31 01:42:47 by raalonso         ###   ########.fr       */
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

void	create_window(t_prog *mlx)
{
	int 	fd;
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
	mlx->win = mlx_new_window(mlx->mlx, mlx->map_width * 32, mlx->map_height * 32, "so_long");
	
}

void	init_img(t_prog *mlx)
{
	int	width = 32;
	int	height = 32;
	int i;
	
	i = 0;
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
		mlx->img_ptr[i] = mlx_xpm_file_to_image(mlx->mlx, mlx->img_path[i], &width, &height);
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

void	render_map(t_prog *mlx, int j, int fd)
{
	char	*line;
	int 	i;
	
	i = 0;
	line = get_next_line(fd);
	while (i <= mlx->map_width && line[i] != '\0')
	{
		if (line[i] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[1], i * 32, j * 32);
		else if (line[i] == '0')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[0], i * 32, j * 32);
		else if (line[i] == 'C')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[3], i * 32, j * 32);
		else if (line[i] == 'E')
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[2], i * 32, j * 32);
		else if (line[i] == 'P')
		{
			mlx->player_x = i;
			mlx->player_y = j;
			mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[4], i * 32, j * 32);
		}
		i++;
	}
}

void	move_player(t_prog *mlx, int direction)
{
	if (direction == KEY_D)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[0], mlx->player_x * 32, mlx->player_y * 32);
		mlx->player_x++;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[4], mlx->player_x * 32, mlx->player_y * 32);
	}
	if (direction == KEY_A)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[0], mlx->player_x * 32, mlx->player_y * 32);
		mlx->player_x--;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[5], mlx->player_x * 32, mlx->player_y * 32);
	}
	if (direction == KEY_S)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[0], mlx->player_x * 32, mlx->player_y * 32);
		mlx->player_y++;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[6], mlx->player_x * 32, mlx->player_y * 32);
	}
	if (direction == KEY_W)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[0], mlx->player_x * 32, mlx->player_y * 32);
		mlx->player_y--;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[7], mlx->player_x * 32, mlx->player_y * 32);
	}
	if (mlx->map[mlx->player_y][mlx->player_x] == 'E')
		exit_game(&*mlx);
}

int	press_key(int key, t_prog *mlx)
{
	static int	i = 0;
	if (key == KEY_ESC)
		exit_game(&*mlx);
	if (mlx->map[mlx->player_y][mlx->player_x + 1] != '1')
	{
		if (key == KEY_D)
		{
			printf("Moves counter: %d\n", i++);
			move_player(&*mlx, KEY_D);
		}
	}
	if (mlx->map[mlx->player_y + 1][mlx->player_x] != '1')
	{
		if (key == KEY_S)
		{
			printf("Moves counter: %d\n", i++);
			move_player(&*mlx, KEY_S);
		}
	}
	if (mlx->map[mlx->player_y - 1][mlx->player_x] != '1')
	{
		if (key == KEY_W)
		{
			printf("Moves counter: %d\n", i++);
			move_player(&*mlx, KEY_W);
		}
	}
	if (mlx->map[mlx->player_y][mlx->player_x - 1] != '1')
	{
		if (key == KEY_A)
		{
			printf("Moves counter: %d\n", i++);
			move_player(&*mlx, KEY_A);
		}
	}
}

int	main(int argc, char **argv)
{
	t_prog	mlx;
	int		j;
	int		fd;

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
