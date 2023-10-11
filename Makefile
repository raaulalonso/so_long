CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
PRINTF = ft_printf/libftprintf.a
SRCS = srcs/so_long.c srcs/player_movement.c srcs/render_map.c \
	srcs/check_errors.c srcs/sprites.c srcs/utils_1.c srcs/utils_2.c \
	srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ft_printf/
	$(CC) $(OBJS) $(PRINTF) -o $(NAME) $(MLXFLAGS) 

srcs/%.o: srcs/%.c
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ft_printf
	rm -rf $(OBJS)

fclean:
	$(MAKE) fclean -C ft_printf
	rm -rf $(OBJS) $(NAME)

re: clean all