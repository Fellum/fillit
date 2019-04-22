NAME = fillit
SRC_DIR = ./fill_it
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = ./objs
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
INC_DIR	:= ./fill_it
LIBFT_DIR = ./libft
LIBFT_INC_DIR = $(LIBFT_DIR)/includes

all: $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@gcc -Wall -Werror -Wextra -I $(INC_DIR) -I $(LIBFT_INC_DIR) -o $@ -c $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	@make -C $(LIBFT_DIR)
	@gcc -Wall -Werror -Wextra  -L $(LIBFT_DIR) -l ft -o $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all
