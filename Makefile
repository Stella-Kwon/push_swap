# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 23:34:08 by suminkwon         #+#    #+#              #
#    Updated: 2024/02/27 12:59:36 by suminkwon        ###   ########.fr        #
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
		lib_ft_splict.c\
		lib_utils.c\

OBJS = $(SRCS:.c=.o)

.c.o:
	${CC} -c $< -o $@
# 일반적으로 Makefile에서 .c.o:라고 선언하면 Make는 자동으로 .c 파일을 .o 파일로 변환하는 규칙을 이해합니다.
all : $(NAME)

$(NAME) : $(OBJS)
	${CC} $(FLAGS) $(OBJS) -o $@

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re
