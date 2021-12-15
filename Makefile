# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 15:40:46 by baubigna          #+#    #+#              #
#    Updated: 2021/12/15 15:45:25 by baubigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

GCC			= gcc

RM			= rm -rf

SRCS		= ft_printf.c \
				ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

GFLAGS		= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

.c.o:		$(GCC) $(GFLAGS) -c $< -o ${<:.c=.o}

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all