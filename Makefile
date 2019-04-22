

SRC_DIR = ./fill_it
INC_DIR	:= ./fill_it
LIBFT_DIR = ./libft
LIB_INC = $(LIBFT_DIR)/includes
SRCS = main.c misc.c output.c read_file.c recursive_solver.c runner.c solve_tetros.c
OBJS = main.o misc.o output.o read_file.o recursive_solver.o runner.o solve_tetros.o

NAME = fillit

all: $(NAME)

%.o:$(SRC_DIR)/%.c
	@gcc -Wall -Werror -Wextra -I $(INC_DIR) -I $(LIB_INC) -o $@ -c $<

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@gcc -Wall -Werror -Wextra  -L./libft/ -lft -o $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all