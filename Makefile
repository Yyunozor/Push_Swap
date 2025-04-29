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
DEBUG_DIR = $(SRCS_DIR)/debug

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

# Debug sources using wildcard for flexibility
DEBUG_SRCS = $(wildcard $(DEBUG_DIR)/*.c)

# Object files derived from sources
OBJS = $(SRCS:.c=.o)
DEBUG_OBJS = $(DEBUG_SRCS:.c=.o)

# ===== MAIN TARGETS =====
all: $(NAME)

$(NAME): ft_printf_lib $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	echo -e "$(GREEN)✅ Push_swap compiled successfully!$(RESET)"

debug: ft_printf_lib $(OBJS) $(DEBUG_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEBUG_OBJS) $(INCLUDES) $(LIBS) -o $(NAME)_debug
	echo -e "$(YELLOW)🔍 Debug version compiled$(RESET)"

# ===== DEPENDENCIES =====
# Use a clear target name to avoid confusion
ft_printf_lib:
	cd $(PRINTF_DIR) && make

# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ===== CLEANING =====
clean:
	cd $(PRINTF_DIR) && make clean
	$(RM) $(OBJS) $(DEBUG_OBJS)
	echo -e "$(BLUE)🧹 Object files cleaned$(RESET)"

fclean:
	cd $(PRINTF_DIR) && make clean
	$(RM) $(OBJS) $(DEBUG_OBJS)
	echo -e "$(BLUE)🧹 Object files cleaned$(RESET)"
	cd $(PRINTF_DIR) && make fclean
	$(RM) $(NAME) $(NAME)_debug
	echo -e "$(BLUE)🧹 Executables removed$(RESET)"

re:
	cd $(PRINTF_DIR) && make clean
	$(RM) $(OBJS) $(DEBUG_OBJS)
	echo -e "$(BLUE)🧹 Object files cleaned$(RESET)"
	cd $(PRINTF_DIR) && make fclean
	$(RM) $(NAME) $(NAME)_debug
	echo -e "$(BLUE)🧹 Executables removed$(RESET)"
	cd $(PRINTF_DIR) && make
	$(foreach src,$(SRCS),\
		$(CC) $(CFLAGS) $(INCLUDES) -c $(src) -o $(src:.c=.o);)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	echo -e "$(GREEN)✅ Push_swap recompiled successfully!$(RESET)"

# ===== PHONY TARGETS =====
.PHONY: all clean fclean re debug ft_printf_lib

