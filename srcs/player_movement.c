/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 23:52:50 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/03 22:57:44 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	move_player(t_prog *mlx, int direction, int img)
{
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
	if (mlx->map[mlx->player_y][mlx->player_x] == 'E')
		exit_game(&*mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr[img],
		mlx->player_x * 32, mlx->player_y * 32);
}

int	press_key(int key, t_prog *mlx)
{
	static int	i = 1;

	if (key == KEY_ESC)
		exit_game(&*mlx);
	if (mlx->map[mlx->player_y][mlx->player_x + 1] != '1' && key == KEY_D)
	{
		printf("Moves counter: %d\n", i++);
		move_player(&*mlx, KEY_D, 4);
	}
	if (mlx->map[mlx->player_y + 1][mlx->player_x] != '1' && key == KEY_S)
	{
		printf("Moves counter: %d\n", i++);
		move_player(&*mlx, KEY_S, 6);
	}
	if (mlx->map[mlx->player_y - 1][mlx->player_x] != '1' && key == KEY_W)
	{
		printf("Moves counter: %d\n", i++);
		move_player(&*mlx, KEY_W, 7);
	}
	if (mlx->map[mlx->player_y][mlx->player_x - 1] != '1' && key == KEY_A)
	{
		printf("Moves counter: %d\n", i++);
		move_player(&*mlx, KEY_A, 5);
	}
}
