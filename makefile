# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 23:34:08 by suminkwon         #+#    #+#              #
#    Updated: 2024/02/27 16:10:17 by suminkwon        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = 	big_sort.c\
		default_pa_b.c default_ra_b.c default_rra_b.c default_sa_b.c\
		error_check.c\
		find_min_max_index.c\
		ft_atoi_m.c\
		insert_args_to_node.c\
		is_sorted.c\
		libft_lst_utils.c\
		pre_sort.c\
		push_swap.c\
		small_sort.c\
		lib_ft_split.c\
		lib_utils.c\
		
OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} -c $< -o $@
	
all : $(NAME)

$(NAME) : $(OBJS)
	${CC} $(FLAGS) $(OBJS) -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re