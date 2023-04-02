NAME			= get_next_line

SRCS_DIR		= srcs/
SRCS_FILES		= get_next_line.c get_next_line_utils.c main.c
SRCS 			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

BONUS_SRCS_FILES=  get_next_line_bonus.c get_next_line_utils_bonus.c main.c
SRCS_BONUS		= $(addprefix $(SRCS_DIR), $(BONUS_SRCS_FILES))

OBJS_DIR		= objs/
OBJS 			= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

BONUS_OBJS		= $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))
BONUS           = get_next_line

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) ${CFLAGS}  -c $< -o $@

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -D BUFFER_SIZE=10
RM				= rm -rf
RM_NAME			= $(RM) $(NAME)

all:			objs $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				$(RM) $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

bonus:			objs all $(BONUS_OBJS)
				$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME)

objs:			
				mkdir -p objs			

.PHONY:			all clean fclean re bonus