/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_rra_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:36:10 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/15 20:38:26 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
*/

void ft_rra(t_stack **a)
{
    t_stack *tmp;

    if (!(*a) || !(*a)->next)
        return;
    tmp = *a;
    *a = ft_lstlast(*a); // make the last element to be the top
    (*a)->next = tmp;    // make the last element to link to the premitive first element
    tmp = tmp->next;     // tmp to direct the original seconde element.
    tmp->next = NULL;    // make it the last
    write(1, "rra\n", 3);
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
    write(1, "rrb\n", 3);
}

void ft_rrr(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
        return;
    tmp = *a;
    *a = ft_lstlast(*a); // make the last element to be the top
    (*a)->next = tmp;    // make the last element to link to the premitive first element
    tmp = tmp->next;     // tmp to direct the original seconde element.
    tmp->next = NULL;    // make it the last
    tmp = *b;
    *b = ft_lstlast(*b);
    (*b)->next = tmp;
    tmp = tmp->next;
    tmp->next = NULL;
    write(1, "rrr\n", 3);
}