# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:59:50 by cemenjiv          #+#    #+#              #
#    Updated: 2021/10/29 10:57:53 by cemenjiv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	get_next_line.c get_next_line_utilis.c \
					

OBJS			= $(SRCS:.c=.o)

NORM 			= norminette

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -D BUFFER_SIZE=42
RM				= rm -f

NAME			= libgnl.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus