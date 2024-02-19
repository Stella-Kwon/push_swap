/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:24:49 by skwon2            #+#    #+#             */
/*   Updated: 2024/02/19 14:15:23 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// # include "./ft_printf/ft_printf.h"
// # include "./ft_printf/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct stack
{
    long long data;
    struct stack *next;
    int index;
    // struct stack *prev;
} t_stack;

int error_check(int arg, char **args, t_stack **a);
long long ft_atoi_m(const char *str);
t_stack *ft_lstlast(t_stack *lst);
void ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack *ft_lstnew(int data, long long i);
void ft_sa(t_stack **a);
void ft_sb(t_stack **b);
void ft_ss(t_stack **a, t_stack **b);
void ft_pa(t_stack **a, t_stack **b);
void ft_pb(t_stack **a, t_stack **b);
void ft_ra(t_stack **a);
void ft_rb(t_stack **b);
void ft_rr(t_stack **a, t_stack **b);
void ft_rra(t_stack **a);
void ft_rrb(t_stack **b);
void ft_rrr(t_stack **a, t_stack **b);
void ft_free(t_stack **lst);
int insert_args(int atoi_i, t_stack **a, long long i);
int is_sorted(t_stack *a);
#endif