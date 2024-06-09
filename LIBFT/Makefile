# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 22:38:51 by pmateo            #+#    #+#              #
#    Updated: 2024/06/09 12:25:01 by pmateo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Werror -Wextra
AR     = ar rcs
RM	   = rm -f
.DEFAULT_GOAL := all

SRC    = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memset.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strdup.c \
			ft_striteri.c ft_strjoin.c ft_strldup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strcmp.c \
			ft_calloc.c ft_split.c ft_memmove.c ft_strmapi.c ft_strchr.c \
			PRINTF/ft_char.c PRINTF/ft_hexa.c PRINTF/ft_nbr.c PRINTF/ft_printf.c PRINTF/ft_ptr.c \
			PRINTF/ft_str.c PRINTF/ft_unbr.c PRINTF/ft_utils.c \
			GNL/get_next_line_bonus.c GNL/get_next_line_utils_bonus.c
			 

BONUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstprint.c

OBJ    = ${SRC:.c=.o}

OBJ_BONUS	= ${BONUS:.c=.o}

NAME  = libft.a

${NAME}: ${OBJ}
	${AR} ${NAME} ${OBJ}

bonus: ${OBJ_BONUS}
	${AR} ${NAME} ${OBJ_BONUS}

all: ${NAME} bonus

clean: 
	${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
		${RM} ${NAME}

re: fclean all