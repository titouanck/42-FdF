# LIBFT
LIBC =	Libft/ft_atoi.c Libft/ft_bzero.c Libft/ft_calloc.c Libft/ft_isalnum.c Libft/ft_isalpha.c \
		Libft/ft_isascii.c Libft/ft_isdigit.c Libft/ft_isprint.c Libft/ft_memchr.c \
		Libft/ft_memcmp.c Libft/ft_memcpy.c Libft/ft_memmove.c Libft/ft_memset.c Libft/ft_strchr.c \
		Libft/ft_strdup.c Libft/ft_strlcat.c Libft/ft_strlcpy.c Libft/ft_strlen.c Libft/ft_strncmp.c \
		Libft/ft_strnstr.c Libft/ft_strrchr.c Libft/ft_tolower.c Libft/ft_toupper.c 

ADDITIONAL =	Libft/ft_itoa.c Libft/ft_putchar_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c Libft/ft_putstr_fd.c \
				Libft/ft_split.c Libft/ft_strjoin.c Libft/ft_strmapi.c Libft/ft_strtrim.c Libft/ft_substr.c Libft/ft_striteri.c

BONUS =	Libft/ft_lstadd_back_bonus.c Libft/ft_lstadd_front_bonus.c Libft/ft_lstclear_bonus.c \
		Libft/ft_lstdelone_bonus.c Libft/ft_lstiter_bonus.c Libft/ft_lstlast_bonus.c \
		Libft/ft_lstmap_bonus.c Libft/ft_lstnew_bonus.c Libft/ft_lstsize_bonus.c

SRCSLIBFT = ${LIBC} ${ADDITIONAL} ${BONUS}

# FT_PRINTF
SRCSPRINTF =	ft_printf/ft_printf.c ft_printf/ft_putadress.c ft_printf/ft_putchar.c \
				ft_printf/ft_puthexa_lower.c ft_printf/ft_puthexa_upper.c ft_printf/ft_putnbr.c \
				ft_printf/ft_putstr.c ft_printf/ft_putunbr.c

# GET_NEXT_LINE
SRCSGETNEXTLINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

# Makefile
SRCSALL = ${SRCSLIBFT} ${SRCSPRINTF} ${SRCSGETNEXTLINE}
OBJS = ${SRCSALL:.c=.o}
DEPS = ${SRCSALL:.c=.d}

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		${CC} ${CFLAGS} -MMD -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
		ar -rsc ${LIB} ${OBJS}

all: 	${LIB}

clean:	
		rm -f ${OBJS} ${DEPS}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
