/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 00:16:04 by raalonso          #+#    #+#             */
/*   Updated: 2023/08/15 21:59:35 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "../libft/libft.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_A 0
# define KEY_W 13
# define KEY_S 1
# define KEY_D 2

typedef struct s_program
{
	void	*mlx;
	void	*win;
	char	*img_path[8];
	void	*img_ptr[8];
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	char	**map;
	char	*map_path;
	int		num_players;
	int		num_exits;
	int		num_collect;
	int		collect_taken;
}	t_prog;

void	move_player(t_prog *mlx, int direction, int img);
int		press_key(int key, t_prog *mlx);
void	exit_game(t_prog *mlx);
void	render_map(t_prog *mlx, int j, int fd);
void	store_map(t_prog *mlx);
void	init_img(t_prog *mlx);
void	create_window(t_prog *mlx);
void	check_walls(t_prog *mlx);
void	error_msg(int type, t_prog *mlx);
void	check_square(t_prog *mlx);
void	check_lines(t_prog *mlx);
void	inicialize_var(t_prog *mlx);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*get_stash(int fd, char *stash);
char	*ft_strjoin_v2(char *stash, char *buffer);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);
char	*clean_stash(char *stash);
char	*get_lines(char *stash);

#endif