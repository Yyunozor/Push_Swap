# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:00:00 by yyuno             #+#    #+#              #
#    Updated: 2025/04/16 03:30:01 by anpayot          #+#    #+#              #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 

# Directories
INC_DIR = includes
LIBFT_DIR = ft_printf2
LIBFT = $(LIBFT_DIR)/libftprintf.a
SRC_DIR = src

# Source files
SRC_FILES = $(SRC_DIR)/main.c \
			$(SRC_DIR)/operators/push.c \
			$(SRC_DIR)/operators/swap.c \
			$(SRC_DIR)/operators/rotate.c \
			$(SRC_DIR)/operators/reverse_rotate.c \
			$(SRC_DIR)/utils/stack_init.c \
			$(SRC_DIR)/utils/stack_utils.c

# Object files (in same location as source files)
OBJ_FILES = $(SRC_FILES:.c=.o)

# Default rule
all: $(NAME)

# Compile libftprintf
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

# Link final executable
$(NAME): $(LIBFT) $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIBFT_DIR) -lftprintf -o $(NAME)

# Clean object files
clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild
re: fclean all

# Debug with fsanitize
debug: CFLAGS += -g -fsanitize=address
debug: re

.PHONY: all clean fclean re debug

