# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 11:45:41 by eedwards          #+#    #+#              #
#    Updated: 2024/06/30 12:58:40 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = check_sorted.c list_args.c min_max.c push_swap.c push.c \
reverse_rotate.c rotate_push.c rotate.c set_indexprev.c solver_utils_ab.c \
solver_utils_ba.c sort_utils.c sort.c swap.c t_stack_utils.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFTA = libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./$(LIBFT) -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT) fclean

re: fclean all