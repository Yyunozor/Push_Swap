NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src
LIBFT_UTILS_DIR = libft_utils
OBJ_DIR = OBJ_DIR

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(LIBFT_UTILS_DIR)/*.c)
OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	echo "Compiling $@"
	$(CC) $(CFLAGS) -o $@ $^
	echo "Compilation complete"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBFT_UTILS_DIR)/%.c | $(OBJ_DIR)
	echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	echo "Cleaning object files..."
	rm -rf $(OBJ_DIR)

fclean: clean
	echo "Cleaning executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
