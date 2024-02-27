/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_rra_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:36:10 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 01:34:53 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_rra(t_stack **a)
{
    t_stack *tmp;

    if (!(*a) || !(*a)->next)
        return;
    tmp = *a;
    *a = ft_lstlast(*a);
    (*a)->next = tmp;
    tmp = tmp->next;
    tmp->next = NULL;
    write(1, "rra\n", 4);
}

void ft_rrb(t_stack **b)
{
    t_stack *tmp;

    if (!(*b) || !(*b)->next)
        return;
    tmp = *b;
    *b = ft_lstlast(*b);
    (*b)->next = tmp;
    tmp = tmp->next;
    tmp->next = NULL;
    write(1, "rrb\n", 4);
}

void ft_rrr(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
        return;
    tmp = *a;
    *a = ft_lstlast(*a);
    (*a)->next = tmp;
    tmp = tmp->next;
    tmp->next = NULL;
    tmp = *b;
    *b = ft_lstlast(*b);
    (*b)->next = tmp;
    tmp = tmp->next;
    tmp->next = NULL;
    write(1, "rrr\n", 4);
}