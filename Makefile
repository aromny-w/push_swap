# **************************************************************************** #
#
#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aromny-w <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 02:41:38 by aromny-w          #+#    #+#              #
#    Updated: 2019/08/10 20:55:28 by aromny-w         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker
NAME2 = push_swap
LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INC)
FWS = -framework OpenGL -framework AppKit

SRCS = initstacks.c setarg.c setpos.c do_op.c do_exit.c is_sorted.c
SRCS := $(addprefix srcs/, $(SRCS))

SRCS1 = checker.c visu.c mlx.c draw.c
SRCS1 := $(addprefix srcs/checker/, $(SRCS1))
SRCS1 += $(SRCS)

SRCS2 = push_swap.c phase_0.c phase_1.c phase_2.c phase_3.c putop.c \
		insertionsort.c getvec.c setparts.c setdistance.c
SRCS2 := $(addprefix srcs/push_swap/, $(SRCS2))
SRCS2 += $(SRCS)

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

INC = -I includes -I libft/includes

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME1) $(NAME2)

$(NAME1): $(LIB) $(OBJS1)
		@$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1) -L libft -lft -lmlx $(FWS)
$(NAME2): $(LIB) $(OBJS2)
		@$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2) -L libft -lft
$(LIB):
		@make -sC libft

clean:
		@make clean -C libft
		@/bin/rm -f $(OBJS1)
		@/bin/rm -f $(OBJS2)

fclean: clean
		@make fclean -C libft
		@/bin/rm -f $(NAME1)
		@/bin/rm -f $(NAME2)

re: fclean all
