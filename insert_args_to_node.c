/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_args_to_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:46:55 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/19 14:39:13 by skwon2           ###   ########.fr       */
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
    (*lst) = NULL;
    // free(lst);
    // lst = NULL; dont need this as they didnt malloc it. it is just the pointer of linked list
}

int    insert_args(int atoi_i, t_stack **a, long long i)
{
    t_stack *new;

    new = NULL;
    if (!(*a))
        new = ft_lstnew(atoi_i, i);
    else if ((*a))
        new = ft_lstnew(atoi_i, i);
    if (!new)
    {
        ft_free(a);
        return (-1);
    }
    printf("\n\n\n-----newnode-----\n\n\n");
    printf("new node data : %lld\n", new->data);
    ft_lstadd_back(a, new);
    return (0);
}

