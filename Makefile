NAME = term3d
DIR = srcs/
FILES = main.c \
	input.c \
	draw.c \
	rotate.c
SRCS = ${addprefix ${DIR},${FILES}}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}
HEADERS = includes/

.c.o:
	${CC} ${CFLAGS} -I${HEADERS} -c $< -o ${<:.c=.o}

all: ${NAME}

$(NAME): ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
