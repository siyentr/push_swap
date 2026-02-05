NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c push_swap.c \
	   utils.c utils_parse.c \
	   libft_calloc.c libft_lst.c

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
