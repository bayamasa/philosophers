# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/25 16:41:14 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

# NAMEとDIR名がかぶっているので実行ファイルが作成できない問題を解決する
SRCDIR = ./philo_d/src/
SRCNAME = 	main.c \
			args_handling.c \
			error_handling.c \
			philo_utils.c \
			philo_utils_2.c \

SRCS = $(addprefix $(SRCDIR), $(SRCNAME))

OBJS = ${SRCS:.c=.o}


CC = gcc 
CFLAGS = -Wall -Werror -Wextra
INC = -I ./philo_d/includes/
all: ${NAME}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

.c.o:
		${CC} ${CFLAGS} $(INC) -c $< -o ${<:.c=.o}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
re:		fclean all

.PHONY: all clean fclean re .c.o
