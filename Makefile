# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eedwards <eedwards@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/30 11:45:41 by eedwards          #+#    #+#              #
#    Updated: 2024/06/30 11:51:40 by eedwards         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = check_sorted.c libft_fun.c list_args.c min_max.c push_swap.c push.c \
rever_rotate.c rotate_push.c rotate.c set_indexprev.c solver_utils_ab,c \
solver_utils_ba.c sort_utils.c sort.c swap.c t_stack_utils.c
OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAGS) -c $?

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus