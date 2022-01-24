# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhirabay <mhirabay@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 13:21:26 by mhirabay          #+#    #+#              #
#    Updated: 2022/01/24 13:22:52 by mhirabay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	main.c \

OBJS = ${SRCS:.c=.o}

CC = gcc 
CFLAGS = -Wall -Werror -Wextra
all: ${NAME}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean: 
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ${lst_NAME} ${lst_OBJS}
re:		fclean all

.PHONY: all clean fclean re .c.o
