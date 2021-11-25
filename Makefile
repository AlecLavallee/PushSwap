SRCS_SORTER =	./srcs/main.c \
				./srcs/sorter/short_suites/short_suites.c \
				./srcs/sorter/long_suites/target_index.c \
				./srcs/sorter/long_suites/keep_push.c \
				./srcs/sorter/long_suites/find_shortest_action.c \
				./srcs/sorter/long_suites/sort.c \

SRCS_COMMON =	./srcs/stack/utils1.c \
				./srcs/stack/utils2.c \
				./srcs/stack/utils3.c \
				./srcs/stack/utils4.c \
				./srcs/utils.c \
				./srcs/actions/push.c \
				./srcs/actions/reverse_rotate.c \
				./srcs/actions/rotate.c \
				./srcs/actions/swap.c \
				./srcs/parsing/parsing_utils.c \
				./srcs/exit/exit.c \

SRCS_CHECKER =	./srcs/checker/main.c \
				./srcs/checker/get_next_line.c \
				./srcs/checker/get_next_line_utils.c \

OBJS_SORTER =	${SRCS_SORTER:.c=.o}
OBJS_COMMON =	${SRCS_COMMON:.c=.o}
OBJS_CHECKER =	${SRCS_CHECKER:.c=.o}

INCLUDE = 		./headers

NAME =			push_swap
NAME_CHECKER =	checker

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
RM = 		rm -rf

all: 		${NAME}

bonus:		checker

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS_COMMON} ${OBJS_SORTER}
			${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME} ${OBJS_COMMON} ${OBJS_SORTER}

${NAME_CHECKER}:	${OBJS_COMMON} ${OBJS_CHECKER}
					${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME_CHECKER} ${OBJS_COMMON} ${OBJS_CHECKER}

clean:
			${RM} ${OBJS_COMMON} ${OBJS_CHECKER} ${OBJS_SORTER}

fclean:	clean
			${RM} ${NAME} ${NAME_CHECKER}

re:			fclean all

.PHONY:		bonus all clean fclean re