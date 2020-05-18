NAME = lem-in
LIB = libft/
SRCS = main/
FLAGS = -Wall -Wextra -Werror -L

all: $(NAME)

$(NAME):
		@make -C $(LIB) re
		@gcc $(SRCS)*.c -o $(NAME) $(FLAGS) $(LIB) -lft

clean:
		@make -C $(LIB) clean

fclean:
		@make -C $(LIB) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
