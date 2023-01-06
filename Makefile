# Makefile
SRCS =	srcs/fdf_atoi_color.c		srcs/fdf_colorgradient.c		srcs/fdf_findrange.c		srcs/fdf_map_to_screen.c \
		srcs/fdf_bresenham.c		srcs/fdf_colorgradient_indice.c	srcs/fdf_free_all.c			srcs/fdf_mouseclick.c \
		srcs/fdf_bresenham_else.c	srcs/fdf_colormap.c				srcs/fdf_generate_map.c		srcs/fdf_map_fill.c \
		srcs/fdf_bresenham_if.c		srcs/fdf_default.c				srcs/fdf_get_scale.c		srcs/fdf_put_pixel.c \
		srcs/fdf.c					srcs/fdf_fileoperations.c		srcs/fdf_keypressed.c		srcs/ft_colors.c \
		srcs/fdf_clear_img.c		srcs/fdf_fill_img.c				

OBJS = ${SRCS:.c=.o}
DEPS = ${SRCS:.c=.d}

# INCLUDES
INCPATH = -I inc/ -I libs/libft -I libs/minilibx -I libs/minilibx-macos

# LIBRAIRIES
LIBFTPATH = -L libs/libft -lft
MLXPATH = -L libs/minilibx -lmlx -lXext -lX11
MLXPATH_MACOS = -L libs/minilibx-macos -lmlx -framework OpenGL -framework AppKit -lm
LIBS = ${LIBFTPATH} ${MLXPATH} ${INCPATH} -lm

# COMPILATION
NAME = FdF
CC = cc
CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${INCPATH} -MMD -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} 
		+$(MAKE) -C libs/minilibx
		+$(MAKE) -C libs/libft
		${CC} -o ${NAME} ${CFLAGS} ${OBJS} ${LIBS}

clean:	
		rm -f ${OBJS} ${DEPS}
		+$(MAKE) -C libs/libft clean

fclean:	clean;
		+$(MAKE) -C libs/libft fclean
		+$(MAKE) -C libs/minilibx clean
		+$(MAKE) -C libs/minilibx-macos clean
		rm -f ${NAME}

all:	${NAME}

bonus:	${NAME}

re:	fclean all

norminette:
		norminette srcs/

# ADAPTATION FOR USAGE ON MACOS
LIBS_MACOS = -D MACOS=1 ${LIBFTPATH} ${MLXPATH_MACOS} ${INCPATH}

macos:	 
		clear
		+$(MAKE) -C libs/minilibx-macos
		+$(MAKE) -C libs/libft
		gcc  -o ${NAME} ${CFLAGS} ${SRCS} ${LIBS_MACOS}
		rm -f ${OBJS} 

macos_re: fclean macos

-include ${DEPS}

.PHONY: all clean fclean re norminette
