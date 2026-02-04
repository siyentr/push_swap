NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c
OBJS = ${SRCS:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${OBJS}  -o ${NAME}

clean : 
		@rm -rf  ${OBJS} 
fclean :
		@rm -rf ${OBJS} ${NAME}

re :  	fclean all

.PHONY: all clean fclean re