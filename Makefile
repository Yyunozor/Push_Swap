# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:00:00 by yyuno             #+#    #+#              #
#    Updated: 2025/05/08 12:34:52 by anpayot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== COLOR MACROS =====
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

# ===== BASIC CONFIGURATION =====
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# ===== DIRECTORY STRUCTURE =====
SRCS_DIR = srcs
UTILS_DIR = $(SRCS_DIR)/utils
OPERATORS_DIR = $(SRCS_DIR)/operators
PARSING_DIR = $(SRCS_DIR)/parsers
ALGORITHMS_DIR = $(SRCS_DIR)/algos
DEBUG_DIR = debug

# ===== EXTERNAL LIBRARIES =====
PRINTF_DIR = ft_printf2
INCLUDES = -Iincludes -I$(PRINTF_DIR)/includes
LIBS = -L$(PRINTF_DIR) -lftprintf

# ===== SOURCE FILES =====
SRCS = $(SRCS_DIR)/main.c \
       $(OPERATORS_DIR)/push.c \
       $(OPERATORS_DIR)/swap.c \
       $(OPERATORS_DIR)/rotate.c \
       $(OPERATORS_DIR)/reverse_rotate.c \
       $(PARSING_DIR)/num_checker.c \
       $(PARSING_DIR)/parse_args.c \
       $(PARSING_DIR)/parse_utils.c \
       $(UTILS_DIR)/stack_utils.c \
	   $(ALGORITHMS_DIR)/sort_small.c \
	   $(ALGORITHMS_DIR)/sort_medium.c \
	   $(ALGORITHMS_DIR)/sort_large.c \
	   $(ALGORITHMS_DIR)/sorting_utils.c \
	   $(ALGORITHMS_DIR)/sorting_utils2.c

# Object files derived from sources
OBJS = $(SRCS:.c=.o)

# ===== MAIN TARGETS =====
all: $(NAME)

$(NAME): ft_printf_lib $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ Push_swap compiled successfully!$(RESET)"

# # ===== DEBUG TARGET =====
# debug:
# 	@echo "$(YELLOW)🔍 Building debug tools...$(RESET)"
# 	@make -C $(DEBUG_DIR)
# 	@echo "$(GREEN)✅ Debug tools ready! Run ./debug/push_swap_debug$(RESET)"

# ===== DEPENDENCIES =====
ft_printf_lib:
	@make -C $(PRINTF_DIR)

# rule for object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ===== CLEANING =====
clean:
	@make -C $(PRINTF_DIR) clean
	@if [ -d "$(DEBUG_DIR)" ] && [ -f "$(DEBUG_DIR)/Makefile" ]; then \
		make -C $(DEBUG_DIR) clean; \
	fi
	$(RM) $(OBJS)
	@echo "$(BLUE)🧹 Object files cleaned$(RESET)"

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@if [ -d "$(DEBUG_DIR)" ] && [ -f "$(DEBUG_DIR)/Makefile" ]; then \
		make -C $(DEBUG_DIR) fclean; \
	fi
	$(RM) $(NAME)
	@echo "$(BLUE)🧹 Executables removed$(RESET)"

re: fclean all

# ===== PHONY TARGETS =====
.PHONY: all clean fclean re debug ft_printf_lib

