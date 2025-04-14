# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpayot <anpayot@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 10:00:00 by yyuno             #+#    #+#              #
#    Updated: 2025/04/14 21:00:09 by anpayot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes

# Directories
LIBFT_DIR = libft
SRCS_DIR = src
OBJS_DIR = src

# Files
SRCS = $(SRCS_DIR)/ft_printf.c \
	   $(SRCS_DIR)/ft_formats.c \
	   $(SRCS_DIR)/ft_numbers.c

OBJS = $(SRCS:.c=.o)

# Rules
all: $(NAME)

# Build libft first
$(LIBFT_DIR)/libft.a:
	@echo "Compiling ft_printf2... "
	@$(MAKE) -C $(LIBFT_DIR)

# Compile individual files
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Build printf library
$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	@cp $(LIBFT_DIR)/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "ft_printf2 successfully compiled! "

# Clean up
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re