#Name
NAME		=	lol

#Commands
CC			=	gcc
RM			=	rm -rf
MAKE		=	make --no-print-directory
MKD			=	mkdir -p
INCLUDES	=	-I $(H_DIR)/
FLAGS		=	$(CFLAGS) $(MLX_FLAGS)
CFLAGS		=	-Wall -Wextra -Werror -g -lpthread -D_REENTRANT
FSAN_FLAGS	=	-fsanitize=address

#SRC_FILES
SRCS	=	test.c
#Object
OBJS	=	$(SRCS:.c=.o)

$(O_DIR)/%.o:	%.c

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(FLAGS) 

all:	$(NAME)

fsan:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(FSAN_FLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
