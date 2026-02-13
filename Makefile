NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = main.c main_parse.c push_swap.c \
	strat_simple.c strat_medium.c strat_complex.c \
	strat_simple_utils.c strat_medium_utils.c \
	operations_utils.c operations_put.c operations_1.c operations_2.c operations_3.c \
	utils_1.c utils_2.c utils_parse.c put_bench.c \
	libft_calloc.c libft_lst.c libft_split.c libft_utils.c libft_put_fd.c
OBJS = ${SRCS:.c=.o}

BONUS_SRCS = checker_bonus.c checker_ops_bonus.c main_parse.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c utils_1.c utils_parse.c\
	operations_utils.c operations_put.c operations_1.c operations_2.c operations_3.c \
	libft_calloc.c libft_lst.c libft_split.c libft_utils.c libft_put_fd.c
BONUS_OBJS = ${BONUS_SRCS:.c=.o}

all: ${NAME}
bonus: ${BONUS_NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${BONUS_NAME}: ${BONUS_OBJS}
	@${CC} ${CFLAGS} ${BONUS_OBJS} -o ${BONUS_NAME}

clean:
	@rm -rf ${OBJS} ${BONUS_OBJS}

fclean:
	@rm -rf ${OBJS} ${BONUS_OBJS} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all bonus clean fclean re
