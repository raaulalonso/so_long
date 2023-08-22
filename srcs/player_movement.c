/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:52:50 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/23 00:52:03 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	remove_collect(t_prog *mlx, int y, int x)
{
	mlx->map[y][x] = '0';
	return (1);
}

int	check_collectable(t_prog *mlx, int direction)
{
	if (mlx->map[mlx->player_y][mlx->player_x + 1] == 'C'
		&& direction == KEY_D)
		return (remove_collect(&*mlx, mlx->player_y, mlx->player_x + 1));
	else if (mlx->map[mlx->player_y][mlx->player_x - 1] == 'C'
		&& direction == KEY_A)
		return (remove_collect(&*mlx, mlx->player_y, mlx->player_x - 1));
	else if (mlx->map[mlx->player_y + 1][mlx->player_x] == 'C'
		&& direction == KEY_S)
		return (remove_collect(&*mlx, mlx->player_y + 1, mlx->player_x));
	else if (mlx->map[mlx->player_y - 1][mlx->player_x] == 'C'
		&& direction == KEY_W)
		return (remove_collect(&*mlx, mlx->player_y - 1, mlx->player_x));
	else
		return (0);
}

void	check_exit(t_prog *mlx)
{
	if (mlx->collect_taken == mlx->num_collect)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->win,
			mlx->img_ptr[3], mlx->exit_x, mlx->exit_y);
	}
}

void	move_player(t_prog *mlx, int direction, int img)
{
	static int	i = 1;

	printf("Moves counter: %d\n", i++);
	if (check_collectable(*&mlx, direction) == 1)
		mlx->collect_taken++;
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[0],
		mlx->player_x * 32, mlx->player_y * 32);
	if (direction == KEY_D)
		mlx->player_x++;
	if (direction == KEY_A)
		mlx->player_x--;
	if (direction == KEY_S)
		mlx->player_y++;
	if (direction == KEY_W)
		mlx->player_y--;
	if (mlx->map[mlx->player_y][mlx->player_x] == 'E'
		&& mlx->collect_taken == mlx->num_collect)
		exit_game(&*mlx);
	check_exit(&*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[img],
		mlx->player_x * 32, mlx->player_y * 32);
}

int	press_key(int key, t_prog *mlx)
{
	static int	k = 8;

	if (k == 13)
		k = 8;
	if (key == KEY_ESC)
		exit_game(&*mlx);
	animate(&*mlx, k);
	if (mlx->map[mlx->player_y][mlx->player_x + 1] != '1'
		&& (mlx->map[mlx->player_y][mlx->player_x + 1]
		!= 'E' || mlx->collect_taken == mlx->num_collect) && key == KEY_D)
		move_player(&*mlx, KEY_D, 4);
	if (mlx->map[mlx->player_y + 1][mlx->player_x] != '1'
		&& (mlx->map[mlx->player_y + 1][mlx->player_x]
		!= 'E' || mlx->collect_taken == mlx->num_collect) && key == KEY_S)
		move_player(&*mlx, KEY_S, 6);
	if (mlx->map[mlx->player_y - 1][mlx->player_x] != '1'
		&& (mlx->map[mlx->player_y - 1][mlx->player_x]
		!= 'E' || mlx->collect_taken == mlx->num_collect) && key == KEY_W)
		move_player(&*mlx, KEY_W, 7);
	if (mlx->map[mlx->player_y][mlx->player_x - 1] != '1'
		&& (mlx->map[mlx->player_y][mlx->player_x - 1]
		!= 'E' || mlx->collect_taken == mlx->num_collect) && key == KEY_A)
		move_player(&*mlx, KEY_A, 5);
	k++;
	return (0);
}
