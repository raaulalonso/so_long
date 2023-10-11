CC = gcc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS  = rc

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putnbr_fd.c ft_putnbr_unsigned.c ft_puthex.c \
	ft_putmem.c ft_puthexmem.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${AR} ${ARFLAGS} ${NAME} ${OBJS}

clean :
	rm -rf ${OBJS}

fclean :
	rm -rf ${NAME} ${OBJS}

re: clean all