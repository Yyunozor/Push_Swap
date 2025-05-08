# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 15:40:21 by anpayot           #+#    #+#              #
#    Updated: 2025/05/05 14:35:56 by anpayot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap_debug

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS_DIR = ../srcs
DEBUG_DIR = .

OPERATORS_DIR = $(SRCS_DIR)/operators
PARSERS_DIR = $(SRCS_DIR)/parsers
UTILS_DIR = $(SRCS_DIR)/utils
ALGOS_DIR = $(SRCS_DIR)/algos

SRCS = $(DEBUG_DIR)/debug_main.c \
	  $(DEBUG_DIR)/stack_visualizer.c \
	  $(DEBUG_DIR)/test_generator.c \
	  $(OPERATORS_DIR)/push.c \
	  $(OPERATORS_DIR)/swap.c \
	  $(OPERATORS_DIR)/rotate.c \
	  $(OPERATORS_DIR)/reverse_rotate.c \
	  $(PARSERS_DIR)/num_checker.c \
	  $(PARSERS_DIR)/parse_args.c \
	  $(PARSERS_DIR)/parse_utils.c \
	  $(UTILS_DIR)/stack_utils.c \
	  $(ALGOS_DIR)/sort_small.c \
	  $(ALGOS_DIR)/sort_medium.c \
	  $(ALGOS_DIR)/sort_large.c \
	  $(ALGOS_DIR)/sorting_utils.c \
	  $(ALGOS_DIR)/sorting_utils2.c

OBJS = $(SRCS:.c=.o)

# Include dir
INCLUDES = -I ../includes

# Printf and libft
PRINTF_DIR = ../ft_printf2
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Colors for output
RESET = \033[0m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m

# Rules
all: $(NAME) test_large

$(NAME): $(PRINTF) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(PRINTF)
	@echo "$(GREEN)Debug executable created!$(RESET)"

$(PRINTF):
	@echo "$(BLUE)Building printf library...$(RESET)"
	@make -C $(PRINTF_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean

re: fclean all

# Add test_large target
test_large: test_large.c
	@echo "$(YELLOW)Compiling test_large utility...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) test_large.c -o test_large $(PRINTF)
	@echo "$(GREEN)✅ test_large utility created!$(RESET)"

.PHONY: all clean fclean re