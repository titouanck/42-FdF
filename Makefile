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
# (CFLAGS : Only absent during program design)

.c.o:
		${CC} ${CFLAGS} ${LIBS} -MMD -c $< -o ${<:.c=.o}

${EXEC}:	${OBJS} 
		+$(MAKE) -C minilibx-linux
		+$(MAKE) -C libft
		gcc -o ${EXEC} ${CFLAGS} ${OBJS} ${LIBS}
		rm -f ${OBJS} ${DEPS}
# (last line : Only present during program design)

all:	${EXEC}

macos:	 
		clear
		+$(MAKE) -C minilibx-macos
		+$(MAKE) -C libft
		gcc  -o ${EXEC} -fsanitize=address -g3 ${CFLAGS} ${SRCS} ${LIBS_MACOS}
		rm -f ${OBJS} ${DEPS}
# (last line : Only present during program design)

run:	all
		clear
		valgrind ./FdF 

macos_run:	macos
		clear
		./FdF 

clean:	
		rm -f ${OBJS} ${DEPS}
		+$(MAKE) -C libft clean

fclean:	clean;
		+$(MAKE) -C libft fclean
		+$(MAKE) -C minilibx-linux clean
		+$(MAKE) -C minilibx-macos clean
		rm -f ${EXEC}

re:	fclean all

macos_re: fclean macos

norminette:
		norminette *.c *.h

-include ${DEPS}

.PHONY: all clean fclean re macos
