CC = cc
FLAGS = -Werror -Wextra -Wall -g -g3
RM = rm -f
.DEFAULT_GOAL := all

NAME = test_pipex

DIR_LIBFT = ../LIBFT
LIBFT = 	${DIR_LIBFT}/libft.a

DIRINC_LIBFT = 		${DIR_LIBFT}/INCLUDES
DIRINC_TEST_PIPEX = ./INCLUDES
INCFILES = 			${DIRINC_TEST_PIPEX}/test_pipex.h

DIR_SRCS = 			./SRCS/
SRCS = 				env.c

OBJ = ${SRCS:.c=.o}

%.o: ${DIR_SRCS}%.c ${INCFILES}
	${CC} ${FLAGS} -c $< -o $@ -I ${DIRINC_TEST_PIPEX} -I ${DIR_LIBFT}

${LIBFT}:
	${MAKE} -s -C ${DIR_LIBFT}

${NAME}: ${OBJ} ${OBJ_INIT} ${LIBFT} ${INCFILES}
	${CC} ${FLAGS} -o ${NAME} ${OBJ} ${OBJ_INIT} -I ${DIRINC_TEST_PIPEX} -I ${DIRINC_LIBFT} -L ${DIR_LIBFT} -lft

all: ${LIBFT} ${NAME}
		@echo "\033[1;5;32m# test_pipex READY ! #\033[0m"

clean:
		@${MAKE} -s -C ${DIR_LIBFT} clean
		@${RM} ${OBJ} ${OBJ_BONUS}
		@echo "\033[1;9;35m# No more object files. #\033[0m"

fclean: clean
		@${MAKE} -s -C ${DIR_LIBFT} fclean
		@${RM} ${NAME} ${NAME_BONUS}
		@echo "\033[1;9;35m# No more executable files. #\033[0m"

re: fclean all

.PHONY: all re clean fclean