NAME = term3d
DIR = srcs/
FILES = main.c \
	camera_init.c \
	display_draw.c \
	display_draw_getdepth.c \
	display_print.c \
	display_init.c \
	vertex_rotate.c \
	vertex_rotateall.c \
	vertex_expandall.c \
	vertex_magnitude.c \
	tm_create_model_vertexes.c \
	tm_read_file.c \
	tm_print_error_exit.c \
	tm_split.c \
	tm_strjoin.c \
	tm_vector_utils.c \
	tm_wrapper.c
SRCS = ${addprefix ${DIR},${FILES}}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
OBJS = ${SRCS:.c=.o}
HEADERS = includes/

.c.o:
	${CC} ${CFLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lm

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

test: $(NAME)
	./test.sh

.PHONY: all clean fclean re
