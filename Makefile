CC = gcc
CFLAGS = -Wall -Wextra -Werror
LBFLAGS = -lmlx -L ./mlx -lXext -L/usr/X11/lib -lX11 -framework OpenGL -framework AppKit
NAME = so_long
SRCS = srcs/so_long.c srcs/player_movement.c srcs/render_map.c srcs/check_errors.c \
	srcs/get_next_line.c srcs/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	arch -x86_64 $(CC) $(OBJS) -o $(NAME) $(LBFLAGS) 

srcs/%.o: srcs/%.c
	arch -x86_64 $(CC) -g $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean:
	make fclean -C libft
	rm -rf $(OBJS) $(NAME)

re: clean all