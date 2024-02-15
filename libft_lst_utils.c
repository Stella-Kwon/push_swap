/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:57:21 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/15 20:33:50 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_lstlast(t_stack *lst) // 나중에 library연결해서 해보자고
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}
t_stack *ft_lstnew(int data) // 나중에 library연결해서 해보자고
{
    t_stack *new; 
    
    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->data = data;
    new->next = NULL;
    // new->prev = NULL;
    // new->index = 0;
    return (new);
}
void ft_lstadd_back(t_stack **lst, t_stack *new) // 나중에 library연결해서 해보자고
{
    t_stack *temp_last;

    if (!lst || !new)
        return;
    if (!(*lst))
        *lst = new;
    else
    {
        temp_last = ft_lstlast(*lst);
        temp_last->next = new;
    }
}

