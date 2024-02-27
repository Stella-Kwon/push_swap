/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_pa_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:35:02 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 01:33:26 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*b))
        return;
    tmp = *a;
    *a = *b;
    *b = (*b)->next; 
    (*a)->next = tmp; 
    write(1, "pa\n", 3);
}

void ft_pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*a))
        return;
    tmp = *b;
    *b = *a;
    *a = (*a)->next;
    (*b)->next = tmp;
    write(1, "pb\n", 3);
}
