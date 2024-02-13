NAME = fractol
SRCS = main.c str_utils.c

OBJS = ${SRCS:.c=.o}
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra Werror

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re