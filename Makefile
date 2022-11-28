# Makefile
SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

EXEC = FdF

CC = gcc

LIBFTPATH = -I libft -L libft -lft
MLXPATH = -I minilibx-linux -L minilibx-linux -lmlx -lXext -lX11

LIBS = ${LIBFTPATH} ${MLXPATH}

CFLAGS = # -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${LIBS} -MMD -c $< -o ${<:.c=.o}

${EXEC}:	${OBJS} 
		clear
		+$(MAKE) -C minilibx-linux
		+$(MAKE) -C libft
		gcc -o ${EXEC} ${CFLAGS} ${OBJS} ${LIBS}

all: 	${EXEC}

run:	all
		./FdF 

clean:	
		rm -f ${OBJS} ${DEPS}

fclean:	clean;
		+$(MAKE) -C minilibx-linux clean
		+$(MAKE) -C libft fclean
		rm -f ${EXEC}

re:	fclean all

-include ${DEPS}

.PHONY: all clean fclean re
