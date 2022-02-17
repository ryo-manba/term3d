NAME = term3d
DIR = srcs/
FILES = main.c \
	draw.c \
	rotate.c \
	tm_file_read.c \
	tm_print_error_exit.c \
	tm_split.c \
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

.PHONY: all clean fclean re
