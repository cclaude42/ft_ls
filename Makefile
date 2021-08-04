###################################
# ft_ls
###################################

NAME = ft_ls

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes -I libft/includes

LIBFT = libft/libft.a

LFT = -L libft/ -lft

FILES = ft_ls options print

SRC = $(addsuffix .c, $(addprefix srcs/, $(FILES))) \

OBJ = $(SRC:c=o)

###################################
# Methods
###################################

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@echo "\033[0;32m\n\nCompiling ft_ls..."
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LFT)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating ft_ls objects... %-20.20s\r" $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@make -C libft --no-print-directory

clean:
	@make clean -C libft --no-print-directory
	@echo "\033[0;31m\nDeleting ft_ls objects..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@make fclean -C libft --no-print-directory
	@echo "\033[0;31m\nDeleting ft_ls objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting ft_ls executable..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re
