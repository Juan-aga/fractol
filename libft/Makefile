# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 17:38:15 by juan-aga          #+#    #+#              #
#    Updated: 2023/01/13 23:26:41 by juan-aga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS 		=-I ./include

NAME		= libft.a

CC			= gcc ${FLAGS}

FLAGS		= -Wall -Wextra -Werror

ifdef DEBUG
	FLAGS += -g
endif

ifdef LEAKS
	FLAGS += -fsanitize=address 
endif

REMOVE		= rm -f

DIR_LFT		= ./src/src_libft

DIR_PF		= ./src/src_printf

DIR_GNL		= ./src/src_get_next_line

DIR_FRACTOL	= ./src/src_fractol

SRC_LFT		= ft_isalpha.c			\
			 ft_isdigit.c			\
			 ft_isalnum.c			\
			 ft_isascii.c			\
			 ft_isprint.c			\
			 ft_strlen.c			\
			 ft_memset.c			\
			 ft_bzero.c				\
			 ft_memcpy.c			\
			 ft_memmove.c			\
			 ft_strlcpy.c			\
			 ft_strlcat.c			\
			 ft_toupper.c			\
			 ft_tolower.c			\
			 ft_strchr.c			\
			 ft_strrchr.c			\
			 ft_strncmp.c			\
			 ft_memchr.c			\
			 ft_memcmp.c			\
			 ft_strnstr.c			\
			 ft_atoi.c				\
			 ft_calloc.c			\
			 ft_strdup.c			\
			 ft_substr.c			\
			 ft_strjoin.c			\
			 ft_strtrim.c			\
			 ft_split.c				\
			 ft_itoa.c				\
			 ft_strmapi.c			\
			 ft_striteri.c			\
			 ft_putchar_fd.c		\
			 ft_putstr_fd.c			\
			 ft_putendl_fd.c		\
			 ft_putnbr_fd.c			\
			 ft_lstnew.c			\
			 ft_lstadd_front.c		\
			 ft_lstsize.c			\
			 ft_lstlast.c			\
			 ft_lstadd_back.c		\
			 ft_lstdelone.c			\
 			 ft_lstclear.c			\
			 ft_lstiter.c			\
			 ft_lstmap.c

SRC_PF		= ft_printf.c			\
			 ft_printf_utils.c

SRC_GNL		= get_next_line.c		\
			 get_next_line_utils.c

SRC_FRACTOL	= ft_chrjoin.c			\
			  ft_ftoa.c				\
			  ft_atof.c				\
			  ft_strjoin_va.c		\
			  ft_maths.c

SRC			= $(addprefix ${DIR_LFT}/,${SRC_LFTI})	\
			$(addprefix ${DIR_PF}/,${SRC_PF})		\
			$(addprefix ${DIR_GNL}/,${SRC_GNL})		\
			$(addprefix ${DIR_FRACTOL}/,${SRC_FRACTOL})

OBJ_LFT		= $(addprefix ${DIR_LFT}/,${SRC_LFT:.c=.o})

OBJ_PF		= $(addprefix ${DIR_PF}/,${SRC_PF:.c=.o})

OBJ_GNL		= $(addprefix ${DIR_GNL}/,${SRC_GNL:.c=.o})

OBJ_FRACTOL	= $(addprefix ${DIR_FRACTOL}/,${SRC_FRACTOL:.c=.o})


OBJ			= ${OBJ_LFT}			\
			${OBJ_PF}				\
			${OBJ_GNL}				\
			${OBJ_FRACTOL}

%.o: %.c
			@${CC} ${CFLAGS} -o $@ -c $< && printf "Compiling: $(notdir $<\n)"

all:		${NAME}

${NAME}:	${OBJ}
			@echo "${NAME} objects files were created\n"
			@ar -rcs ${NAME} ${OBJ}
			@echo "${NAME} was created\n"
		
clean:		
			@${REMOVE} ${OBJ}
			@echo "${NAME} objects files were deleted\n"

fclean:		clean 
			${REMOVE} ${NAME}
			@echo "${NAME} was deleted\n"

re:			fclean ${NAME}

.PHONY:		all clean fclean re
