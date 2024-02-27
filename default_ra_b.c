/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_ra_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:37:26 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 01:33:53 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ra(t_stack **a)
{
    t_stack *tmp;

    if (!(*a) || !(*a)->next)
        return;
    tmp = *a;
    *a = ft_lstlast(*a);
    (*a)->next = tmp; 
    *a = tmp->next;
    tmp->next = NULL; 
    write(1, "ra\n", 3);
}

void ft_rb(t_stack **b)
{
    t_stack *tmp;

    if (!(*b) || !(*b)->next)
        return;
    tmp = *b;
    *b = ft_lstlast(*b);
    (*b)->next = tmp;
    *b = tmp->next;
    tmp->next = NULL;
    write(1, "rb\n", 3);
}

void ft_rr(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
        return;
    tmp = *a;
    *a = ft_lstlast(*a);
    (*a)->next = tmp;
    *a = tmp->next;
    tmp->next = NULL;
    tmp = *b;
    *b = ft_lstlast(*b);
    (*b)->next = tmp;
    *b = tmp->next;
    tmp->next = NULL;
    write(1, "rr\n", 3);
}
