/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_pa_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:35:02 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/15 20:38:46 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
 */

void ft_pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*b))
        return;
    tmp = *a;         // *the first element of the a stack
    *a = *b;          // the first element of the a stack will be stack b's first element
    *b = (*b)->next;  // the first elements should be now reannounced to original 2nd element.
    (*a)->next = tmp; // the first element given from stack b should connet with the original first element from stack a.
    write(1, "pa\n", 3);
}
/*
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
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
