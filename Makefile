# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 12:18:42 by juan-aga          #+#    #+#              #
#    Updated: 2023/01/13 23:22:51 by juan-aga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	fractol

LIBMLX			:= ./MLX42

LIBFT			:= ./libft

HEADERS			:=	-I ${LIBMLX}/include/MLX42 -I ./include -I ${LIBFT}/include

LIBS			:=	${LIBMLX}/libmlx42.a ${LIBFT}/libft.a

CC				:=	gcc

RM				=	rm -f

CFLAGS			:=	-Wall -Wextra -Werror -Wunreachable-code -Ofast

ifdef DEBUG
	CC += -g
	MAKE += DEBUG=1
endif

ifdef LEAKS
	CC += -fsanitize=address 
	MAKE += LEAKS=1
endif

SRC				:=	src/main.c			\
				src/ft_color.c			\
				src/ft_window.c			\
				src/ft_fill_pixel.c		\
				src/ft_fractal.c		\
				src/ft_hooks.c			\
				src/ft_moves.c			\
				src/ft_preview.c		\
				src/ft_maths_complex.c	\
				src/ft_newcolors.c		\
				src/ft_bernstein_color.c

OBJ				:=	${SRC:.c=.o}

%.o: %.c
				@${CC} ${CFLAGS} -o $@ -c $< ${HEADERS} && printf "Compiling: $(notdir $<\n)"

all:			libmlx libft ${NAME}

libft:			
				@${MAKE} -C ${LIBFT}

libmlx:
				@${MAKE} -C ${LIBMLX}

${NAME}:		${OBJ}
				${CC} ${OBJ} ${LIBS} -lglfw -L "/Users/juan-aga/.brew/opt/glfw/lib/" ${HEADERS} -o ${NAME}

clean:
				${RM} ${OBJ}
				@${MAKE} -C ${LIBMLX} clean
				@${MAKE} -C ${LIBFT} clean

fclean:			clean
				${MAKE} -C ${LIBMLX} fclean
				${MAKE} -C ${LIBFT} fclean
				${RM} ${NAME}

re:				fclean all

.PHONY:			${NAME} re clean fclean all libmlx libft leaks
