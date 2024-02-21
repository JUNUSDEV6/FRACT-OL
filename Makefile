NAME = fractol
SRCS = main.c str_utils.c init.c math_utils.c render.c

OBJS = ${SRCS:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra Werror

%.o: %.c
	make -C ./mlx
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g3 -o $(NAME)

all: ${NAME}

clean:
	make clean -C ./mlx
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re