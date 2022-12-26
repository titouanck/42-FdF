# Makefile
SRCS =	srcs/fdf_atoi_color.c		srcs/fdf_colorgradient.c		srcs/fdf_findrange.c		srcs/fdf_map_to_screen.c \
		srcs/fdf_bresenham.c		srcs/fdf_colorgradient_indice.c	srcs/fdf_free_all.c			srcs/fdf_mouseclick.c \
		srcs/fdf_bresenham_else.c	srcs/fdf_colormap.c				srcs/fdf_generate_map.c		srcs/fdf_print_map.c \
		srcs/fdf_bresenham_if.c		srcs/fdf_default.c				srcs/fdf_get_scale.c		srcs/fdf_put_pixel.c \
		srcs/fdf.c					srcs/fdf_fileoperations.c		srcs/fdf_keypressed.c		srcs/ft_colors.c \
		srcs/fdf_clear_img.c		srcs/fdf_fill_img.c				srcs/fdf_map_fill.c

OBJS = ${SRCS:.c=.o}

# INCLUDES - inc
INCPATH = -I inc/

# LIBRAIRIES- libs
LIBFTPATH = -I libs/libft -L libs/libft -lft
MLXPATH = -I libs/minilibx -L libs/minilibx -lmlx -lXext -lX11 -lm
MLXPATH_MACOS = -I libs/minilibx-macos -L libs/minilibx-macos -lmlx -framework OpenGL -framework AppKit -lm
LIBS = ${LIBFTPATH} ${MLXPATH} ${INCPATH}

# COMPILATION
EXEC = FdF
CC = gcc
CFLAGS = -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} ${LIBS} -c $< -o ${<:.c=.o}

${EXEC}:	${OBJS} 
		+$(MAKE) -C libs/minilibx
		+$(MAKE) -C libs/libft
		gcc -o ${EXEC} ${CFLAGS} ${OBJS} ${LIBS}

clean:	
		rm -f ${OBJS} 
		+$(MAKE) -C libs/libft clean

fclean:	clean;
		+$(MAKE) -C libs/libft fclean
		+$(MAKE) -C libs/minilibx clean
		+$(MAKE) -C libs/minilibx-macos clean
		rm -f ${EXEC}

all:	${EXEC}

re:	fclean all

norminette:
		norminette srcs/*.c srcs/*.h

# ADAPTATION FOR USAGE ON MACOS
LIBS_MACOS = -D MACOS=1 ${LIBFTPATH} ${MLXPATH_MACOS}

macos:	 
		clear
		+$(MAKE) -C libs/minilibx-macos
		+$(MAKE) -C libs/libft
		gcc  -o ${EXEC} ${CFLAGS} ${SRCS} ${LIBS_MACOS}
		rm -f ${OBJS} 

macos_re: fclean macos

.PHONY: all clean fclean re run macos macos_run norminette
