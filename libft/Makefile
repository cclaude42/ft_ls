###################################
# My own utility lib
###################################

NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

HEADER = $(addsuffix .h, $(addprefix includes/, libutils get_next_line ft_printf))

###################################
# Files
###################################

FTCHR = count index

FTIS = alnum alpha ascii digit print space spacenl

FTSKIP = space spacenl char chars

FTLST = add_back add_front clear delone iter last map new size

FTMATH = nbrlen hexlen baselen power

FTMEM = bzero calloc memccpy memchr memcmp memcpy memdel memmove memset

FTPUT = char endl nbr str char_fd endl_fd nbr_fd str_fd

FTSTR = chr cmp dup join lcat lcpy len mapi ncmp nstr rchr trim

FTSUB = ft_str/ft_substr ft_str/ft_split

FTTO = tolower toupper atoi itoa

FTEX = gnl/get_next_line printf/ft_printf

FTPRF = flagger branch_csp branch_duxo put_c put_s put_du put_o put_x put_p

SRC = $(addsuffix .c, $(addprefix ft_chr/ft_chr, $(FTCHR))) \
	$(addsuffix .c, $(addprefix ft_chr/ft_is, $(FTIS))) \
	$(addsuffix .c, $(addprefix ft_lst/ft_lst, $(FTLST))) \
	$(addsuffix .c, $(addprefix ft_math/ft_, $(FTMATH))) \
	$(addsuffix .c, $(addprefix ft_mem/ft_, $(FTMEM))) \
	$(addsuffix .c, $(addprefix ft_put/ft_put, $(FTPUT))) \
	$(addsuffix .c, $(addprefix ft_skip/ft_skip_, $(FTSKIP))) \
	$(addsuffix .c, $(addprefix ft_str/ft_str, $(FTSTR)) $(FTSUB)) \
	$(addsuffix .c, $(addprefix ft_to/ft_, $(FTTO))) \
	$(addsuffix .c, $(addprefix ft_, $(FTEX))) \
	$(addsuffix .c, $(addprefix ft_printf/ft_printf_, $(FTPRF))) \

OBJ = $(SRC:.c=.o)

###################################
# Methods
###################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m\n\nCompiling libft..."
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33mGenerating libft objects... %-30.30s\r" $@
	@$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\033[0m"

fclean:
	@echo "\033[0;31m\nDeleting objects..."
	@rm -f $(OBJ)
	@echo "\nDeleting library..."
	@rm -f $(NAME)
	@echo "\033[0m"

re: fclean all

.PHONY: clean fclean re bonus
