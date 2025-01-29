# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 11:45:41 by eedwards          #+#    #+#              #
#    Updated: 2025/01/29 12:56:23 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g -I./incl
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./$(LIBFT) -lft
LIBFT = libft
LIBFTA = libft.a
MAKE_SILENT = make --no-print-directory

SRCS = src/apply_rotate_push.c \
	src/args_to_stack.c \
	src/ps_main.c \
	src/push.c \
	src/reverse_rotate.c \
	src/rotate.c \
	src/solver_utils_ab.c \
	src/solver_utils_ba.c \
	src/sort_345.c \
	src/sort_utils.c \
	src/sort_utils2.c \
	src/sort.c \
	src/swap.c \
	src/t_stack_utils.c \

OBJS = $(SRCS:src/%.c=obj/%.o)

obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE_SILENT) -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "$(NAME) created"

clean:
	@$(RM) -r obj
	@$(MAKE_SILENT) -C $(LIBFT) clean
	@echo "push_swap object files removed"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_SILENT) -C $(LIBFT) fclean
	@echo "$(NAME) removed"

re: fclean all

.PHONY: all clean fclean re