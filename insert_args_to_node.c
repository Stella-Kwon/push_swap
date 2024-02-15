/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_args_to_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:46:55 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/15 22:24:44 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(t_stack **lst)
{
    if (!*lst)
        return;
    while (*lst)
    {
        free(*lst);
        *lst = (*lst)->next;
    }
}

void    insert_args(int atoi_i, t_stack **a)
{
    t_stack *new;

    new = NULL;
    if (!(*a))
        new = ft_lstnew(atoi_i);
    else if ((*a))
        new = ft_lstnew(atoi_i);
    if (!new)
    {
        ft_free(a);
        write(2, "ERROR\n", 6);
        return ;
    }
    printf("\n\n\n-----newnode-----\n\n\n");
    printf("new node data : %lld\n", new->data);
    ft_lstadd_back(a, new);
}

