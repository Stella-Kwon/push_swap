/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_ra_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:37:26 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/25 20:46:30 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.
*/

void ft_ra(t_stack **a)
{
    t_stack *tmp;

    if (!(*a) || !(*a)->next) // Check if the stack is not empty and has more than one element
        return;
    printf("a->index: %lld\n", (*a)->index);
    tmp = *a;            // Save the first element of the stack
    *a = ft_lstlast(*a); // Set the last element as the new top of the stack
    (*a)->next = tmp; 
    *a = tmp->next;      // Update the top of the stack to the second element
    tmp->next = NULL;    // Ensure the last element is the actual end of the list
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