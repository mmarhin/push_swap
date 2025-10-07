# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamarin- <mamarin-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:04:15 by dukim             #+#    #+#              #
#    Updated: 2025/10/07 12:14:54 by mamarin-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

# Libft sources
LIBFT_SRCS = src/libft/ft_atoi.c src/libft/ft_split.c src/libft/ft_putchar_fd.c \
			src/libft/ft_putstr_fd.c src/libft/ft_putendl_fd.c src/libft/ft_memcpy.c \
			src/libft/ft_memmove.c src/libft/ft_memset.c src/libft/ft_lstnew.c \
			src/libft/ft_lstlast.c src/libft/ft_lstadd_back.c src/libft/ft_lstclear.c \
			src/libft/ft_strlen.c src/libft/ft_substr.c src/libft/ft_calloc.c \
			src/libft/ft_bzero.c src/libft/ft_lstdelone.c src/libft/ft_isdigit.c \
			src/libft/ft_strlcpy.c

# Mandatory sources
SRCS = src/mandatory/main.c src/mandatory/optimize1.c src/mandatory/optimize2.c \
		src/mandatory/push_swap.c src/mandatory/push_swap_chunks.c \
		src/mandatory/push_swap_small.c src/mandatory/push_swap_normalize.c \
		src/mandatory/push_swap_positions.c src/mandatory/push_swap_rotate.c \
		src/mandatory/init_stack.c src/mandatory/free_handler.c \
		src/mandatory/utils1.c  \
		src/mandatory/stack_commands.c

# All object files
LIBFT_OBJS := $(LIBFT_SRCS:%.c=%.o)
OBJS := $(SRCS:%.c=%.o)
ALL_OBJS = $(LIBFT_OBJS) $(OBJS)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(ALL_OBJS)
	$(CC) $(CFLAGS) $(ALL_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(ALL_OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
