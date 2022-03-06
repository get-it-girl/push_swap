NAME	= push_swap
NAME_1 = checker

HEADER_PS	= ./push_swap.h

HEADER_GNL	= ./get_next_line.h

LIBFT = libft/libft.a

SRC		=	push_swap_big_sort_1.c push_swap_big_sort_2.c push_swap_big_sort_3.c push_swap_checker.c push_swap_command.c push_swap_small_sort_1.c push_swap.c separate.c push_swap_small_sort_2.c

SRC_CHECKER = checker_1.c get_next_line_utils.c get_next_line.c checker_2.c checker_3.c checker_4.c

OBJ		= ${patsubst %.c,%.o,${SRC}}

OBJ_CHECKER = ${patsubst %.c,%.o,${SRC_CHECKER}}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

all:		 ${LIBFT} ${NAME} ${NAME_1}

${NAME}:	${LIBFT} ${OBJ} ${HEADER_PS}
			${CC} ${OBJ} -L./libft -lft -o ${NAME} 

${LIBFT}:
			make -C ./libft

${NAME_1}:	${LIBFT} ${OBJ_CHECKER} ${HEADER_PS} ${HEADER_GNL}
			${CC} ${OBJ_CHECKER} -L./libft -lft -o ${NAME_1} 

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

clean:	
			${RM} ${OBJ} ${OBJ_CHECKER}
			make -C ./libft fclean

fclean:		clean
			${RM} ${NAME} ${LIBFT} ${NAME_1}

re:			fclean all

.PHONY:		all clean fclean re
