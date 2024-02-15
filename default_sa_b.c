/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_sa_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:58:20 by skwon2            #+#    #+#             */
/*   Updated: 2024/02/15 20:38:40 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.
 */

void    ft_sa(t_stack **a) //in order to give modify access -> giving it with pointer
{
    t_stack *tmp;
    
    if (!(*a) || !(*a)->next)
        //!a is showing there is no elements in stack a at all, or even assigned to any places(no address for stack a)  
            //so doesnt really need this as we check with !(*a)
        //!(*a) -> the first elements is Null which means nothing in the stack now.
        // (*a)->next 한개이상
        // a itself address and where
        return ;
    tmp = *a; // tmp -> 1
    *a  = (*a)->next; // *a = 2 : (1->next)
    tmp->next = (*a)->next; //tmp->next = 3 : (2->next)
    (*a)->next = tmp; // (*a)->next  = 1
    // result : 2 -> 1 -> 3
    write(1, "sa\n", 3);
}

void ft_sb(t_stack **b)
{
    t_stack *tmp;

    if (!(*b) || !(*b)->next)
        return;
    tmp = *b;               // tmp -> 1
    *b = (*b)->next;      // *b = 2 : (1->next)
    tmp->next = (*b)->next; // tmp->next = 3 : (2->next)
    (*b)->next = tmp;       // (*b)->next  = 1
    // result : 2 -> 1 -> 3
    write(1, "sb\n", 3);
}

void    ft_ss(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    
    if (!(*a) || !(*a)->next || !(*b) || !(*b)->next)
        return;
    tmp = *a;               // tmp -> 1
    *a = (*a)->next;        // *a = 2 : (1->next)
    tmp->next = (*a)->next; // tmp->next = 3 : (2->next)
    (*a)->next = tmp;       // (*a)->next  = 1
    tmp = *b;               // tmp -> 1
    *b = (*b)->next;        // *b = 2 : (1->next)
    tmp->next = (*b)->next; // tmp->next = 3 : (2->next)
    (*b)->next = tmp;
    write(1, "ss\n", 3);
}



