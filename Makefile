NAME = lem-in
LIB = libft/
SRCS = main/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@make -C $(LIB) re
		@gcc $(SRCS)*.c -o $(NAME) $(FLAGS) $(LIB)

clean:
		@make -C $(LIB) clean

fclean:
		@make -C $(LIB) fclean
		@/bin/rm -rf $(NAME)

re: fclean all