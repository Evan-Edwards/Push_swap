# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 11:45:41 by eedwards          #+#    #+#              #
#    Updated: 2024/08/14 10:43:02 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc -g
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./$(LIBFT) -lft
LIBFT = libft
LIBFTA = libft.a
MAKE_SILENT = make --no-print-directory

SRCS = apply_rotate_push.c \
	args_to_stack.c \
	ps_main.c \
 	push.c \
	reverse_rotate.c \
	rotate.c \
	solver_utils_ab.c \
	solver_utils_ba.c \
	sort_345.c \
	sort_utils.c \
	sort_utils2.c \
	sort.c \
	swap.c \
	t_stack_utils.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE_SILENT) -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)
	@echo "$(NAME) created"

clean:
	@$(RM) $(OBJS)
	@$(MAKE_SILENT) -C $(LIBFT) clean
	@echo "$(NAME) object files removed"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_SILENT) -C $(LIBFT) fclean
	@echo "$(NAME) removed"
	
re: fclean all

.PHONY: all clean fclean re
