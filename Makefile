# Makefile
SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

EXEC = FdF

CC = gcc

LIBFTPATH = -I libft -L libft -lft

MLXPATH = -I minilibx-linux -L minilibx-linux -lmlx -lXext -lX11
MLXPATH_MACOS = -I minilibx-macos -L minilibx-macos -lmlx -framework OpenGL -framework AppKit

LIBS = ${LIBFTPATH} ${MLXPATH}
LIBS_MACOS = ${LIBFTPATH} ${MLXPATH_MACOS}

CFLAGS = # -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${LIBS} -MMD -c $< -o ${<:.c=.o}

OBJS_MACOS = ${CC} ${CFLAGS} ${LIBS_MACOS} -MMD -c $< -o ${<:.c=.o}

${EXEC}:	${OBJS} 
		clear
		+$(MAKE) -C minilibx-linux
		+$(MAKE) -C libft
		gcc -o ${EXEC} ${CFLAGS} ${OBJS} ${LIBS}

all:	${EXEC}

macos:	${OBJS_MACOS} 
		clear
		+$(MAKE) -C minilibx-macos
		+$(MAKE) -C libft
		gcc -o ${EXEC} ${CFLAGS} ${OBJS_MACOS} ${LIBS_MACOS}

run:	all
		./FdF 

clean:	
		rm -f ${OBJS} ${DEPS}
		+$(MAKE) -C libft clean

fclean:	clean;
		+$(MAKE) -C libft fclean
		+$(MAKE) -C minilibx-linux clean
		+$(MAKE) -C minilibx-macos clean
		rm -f ${AA}

re:	fclean all

-include ${DEPS}

.PHONY: all clean fclean re linux macos
