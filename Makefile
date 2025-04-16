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

# OS Detection
OS := $(shell uname -s)

# Common settings
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Source files
SRCS_DIR = src
UTILS_DIR = $(SRCS_DIR)/utils
OPERATORS_DIR = $(SRCS_DIR)/operators
PARSING_DIR = $(SRCS_DIR)/parsing
ALGORITHMS_DIR = $(SRCS_DIR)/algorithms
DEBUG_DIR = $(SRCS_DIR)/debug

# Platform-specific settings
ifeq ($(OS),Darwin)
    # macOS settings
    PRINTF_DIR = ft_printf2
    INCLUDES = -I./includes -I./$(PRINTF_DIR)/includes
    LIBS = -L./$(PRINTF_DIR) -lftprintf
    MAKE_PRINTF = @make -C $(PRINTF_DIR)
else
    # Linux settings
    PRINTF_DIR = ft_printf2
    INCLUDES = -Iincludes -I$(PRINTF_DIR)/includes
    LIBS = -L./$(PRINTF_DIR) -lftprintf
    MAKE_PRINTF = @make --no-print-directory -C $(PRINTF_DIR)
endif

# Files list (explicit to avoid missing files)
SRCS = $(SRCS_DIR)/main.c \
       $(OPERATORS_DIR)/push.c \
       $(OPERATORS_DIR)/swap.c \
       $(OPERATORS_DIR)/rotate.c \
       $(OPERATORS_DIR)/reverse_rotate.c

# Find all other source files
ifneq ($(wildcard $(UTILS_DIR)/*.c),)
    SRCS += $(wildcard $(UTILS_DIR)/*.c)
endif
ifneq ($(wildcard $(PARSING_DIR)/*.c),)
    SRCS += $(wildcard $(PARSING_DIR)/*.c)
endif
ifneq ($(wildcard $(ALGORITHMS_DIR)/*.c),)
    SRCS += $(wildcard $(ALGORITHMS_DIR)/*.c)
endif

DEBUG_SRCS = $(wildcard $(DEBUG_DIR)/*.c)

OBJS = $(SRCS:.c=.o)
DEBUG_OBJS = $(DEBUG_SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): ft_printf $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)
	@echo "\033[1;32m✅ Push_swap compiled successfully!\033[0m"

debug: ft_printf $(OBJS) $(DEBUG_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(DEBUG_OBJS) $(INCLUDES) $(LIBS) -o $(NAME)_debug

ft_printf:
	$(MAKE_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
ifeq ($(OS),Darwin)
	@make -C $(PRINTF_DIR) clean
else
	@make --no-print-directory -C $(PRINTF_DIR) clean
endif
	$(RM) $(OBJS) $(DEBUG_OBJS)
	@echo "\033[1;34m🧹 Object files cleaned\033[0m"

fclean: clean
ifeq ($(OS),Darwin)
	@make -C $(PRINTF_DIR) fclean
else
	@make --no-print-directory -C $(PRINTF_DIR) fclean
endif
	$(RM) $(NAME) $(NAME)_debug
	@echo "\033[1;34m🧹 Executables removed\033[0m"

re: fclean all

.PHONY: all ft_printf clean fclean re debug

