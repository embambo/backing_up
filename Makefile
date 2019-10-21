# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: embambo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/15 13:18:34 by embambo           #+#    #+#              #
#    Updated: 2019/10/01 11:29:33 by embambo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap.a
NAME2 = checker.a
GCC = -Wall -Werror -Wextra -c

SRCS1 = push_swap.c parse_args.c portions.c portions_helper.c push_back_to_a.c\
	 basic_sort.c bubble_sort.c is_sorted.c operations.c operations1.c\
	 operations2.c rr_multi.c rra_multi.c operations_helper.c sort_5_helper.c

SRCS2 = checker.c parse_args.c operations.c operations1.c operations2.c\
	  is_sorted.c 

OBJECTS1 = push_swap.o parse_args.o portions.o portions_helper.o push_back_to_a.o\
	 basic_sort.o bubble_sort.o is_sorted.o operations.o operations1.o\
	 operations2.o rr_multi.o rra_multi.o operations_helper.o sort_5_helper.o

OBJECTS2 = checker.o parse_args.o operations.o operations1.o operations2.o \
	  is_sorted.o 

HDR 		= -I./includes
LIBFT_HDR 	= -I./libft/includes
LIB_BINARY	= -L./libft -lft
LIBFT		= libft/libft.a
INCLUDES = ./

$(LIBFT):
		@make -C libft re

all: $(LIBFT) $(NAME1) 

$(NAME1):
		@gcc $(GCC) -I $(INCLUDES)  $(SRCS1)
		@gcc $(GCC) -I $(INCLUDES) $(SRCS2)
		@ar rc $(NAME1) $(OBJECTS1)
	   	@ar rc $(NAME2) $(OBJECTS2)
		@RANLIB $(NAME1)
		@RANLIB $(NAME2)
		@gcc -o push_swap  push_swap.c push_swap.a checker.a libft/libft.a 	
		@gcc -o checker  checker.c push_swap.a checker.a libft/libft.a 

clean:
		@rm -f $(OBJECTS1)
		@rm -f $(OBJECTS2)

fclean: clean
		@rm -f $(NAME1)
		@rm -f $(NAME2)

re: fclean all
