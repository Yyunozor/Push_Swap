# OS Detection
OS := $(shell uname -s)

# Variables
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_numlen.c ft_isvalid_base.c ft_atoi_base.c ft_atol.c ft_revstr.c ft_itoa_base.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_isspace.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_swap.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putlong.c \
		ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c \
		ft_ulltoa_base.c ft_numlen_base.c

OBJ = $(SRC:.c=.o)

# Platform-specific settings
ifeq ($(OS),Darwin)
    # macOS settings
    ECHO_COMPILED = echo "Library compiled."
    ECHO_SUCCESS = echo "libft.a created successfully!"
    ECHO_REMOVED = echo "Object files removed."
    ECHO_LIBREMOVED = echo "Library removed."
else
    # Linux settings
    ECHO_COMPILED = echo "\033[1;32m✓ libft objects compiled\033[0m"
    ECHO_SUCCESS = echo "\033[1;32m✓ libft.a ready\033[0m"

    ECHO_REMOVED = echo "\033[1;34m✓ libft objects cleaned\033[0m"
    ECHO_LIBREMOVED = echo "\033[1;34m✓ libft.a removed\033[0m"
endif

# Default target
all: $(NAME)
	$(ECHO_SUCCESS)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	$(ECHO_COMPILED)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(ECHO_REMOVED)

fclean: clean
	rm -f $(NAME)
	$(ECHO_LIBREMOVED)

re: fclean all

.PHONY: all clean fclean re