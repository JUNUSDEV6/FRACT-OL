NAME = fractol
SRCS = main.c str_utils.c init.c math_utils.c render.c event.c

OBJS = ${SRCS:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SAN = -fsanitize=address -g3

%.o: %.c
	$(CC) $(CFLAGS) $(SAN) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(SAN) -o $(NAME) mlx/libmlx.a

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re