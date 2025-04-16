# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:00:00 by yyuno             #+#    #+#              #
#    Updated: 2025/04/14 21:00:09 by anpayot          #+#    #+#              #
#                                                                              #
# **************************************************************************** #

# OS Detection
OS := $(shell uname -s)

# Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

# Directories
LIBFT_DIR = libft
SRCS_DIR = src
OBJS_DIR = src

# Platform-specific settings
ifeq ($(OS),Darwin)
    # macOS settings
    MAKE_LIBFT = @$(MAKE) -C $(LIBFT_DIR)
    ECHO_START = @echo "Compiling ft_printf2... "
    ECHO_DONE = @echo "ft_printf2 successfully compiled! "
else
    # Linux settings
    MAKE_LIBFT = @$(MAKE) --no-print-directory -C $(LIBFT_DIR)
    ECHO_START = @echo "\033[1;33m⚙️  Building ft_printf2...\033[0m"
    ECHO_DONE = @echo "\033[1;32m✅ ft_printf2 library ready\033[0m"
endif

# Files
SRCS = $(SRCS_DIR)/ft_printf.c \
	   $(SRCS_DIR)/ft_formats.c \
	   $(SRCS_DIR)/ft_numbers.c

OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

# Build libft first
$(LIBFT_DIR)/libft.a:
	$(ECHO_START)
	$(MAKE_LIBFT)

# Compile individual files
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build printf library
$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	@cp $(LIBFT_DIR)/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	$(ECHO_DONE)

# Clean up
clean:
ifeq ($(OS),Darwin)
	@$(MAKE) -C $(LIBFT_DIR) clean
else
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
endif
	@rm -f $(OBJS)

fclean: clean
ifeq ($(OS),Darwin)
	@$(MAKE) -C $(LIBFT_DIR) fclean
else
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
endif
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re