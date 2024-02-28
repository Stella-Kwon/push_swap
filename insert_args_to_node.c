/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_args_to_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:46:55 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 16:55:31 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(t_stack **lst)
{
    t_stack *tmp;
    if (!*lst)
        return;
    while (*lst != NULL)
    {
        tmp = *lst;
        (*lst) = (*lst)->next;
        free(tmp);
        tmp = NULL;
    }
}

// int    insert_args(int atoi_i, t_stack **a, long long i)
// {
//     t_stack *new;

//     new = NULL;
//     if (!(*a))
//         new = ft_lstnew(atoi_i, i);
//     else if ((*a))
//         new = ft_lstnew(atoi_i, i);
//     if (!new)
//     {
//         ft_free(a);
//         return (-1);
//     }
//     printf("\n\n\n-----newnode-----\n\n\n");
//     printf("new node data : %lld\n", new->data);
//     ft_lstadd_back(a, new);
//     return (0);
// }
int insert_args(long long atoi_i, t_stack **a, long long *arg_i)
{
    t_stack *new;

    new = NULL;
    if (!(*a)) // 처음에는 null값으로 들어온다. 즉 a가 가르키는 주소값이없는거지.
        new = ft_lstnew(atoi_i);
    else if ((*a))
        new = ft_lstnew(atoi_i);
    if (!new)
    {
        ft_free(a);
        return (-1);
    }
    printf("\n\n\n-----newnode-----\n\n\n");
    printf("atoi_i : %lld\n", atoi_i);
    printf("new node data : %lld\n", new->data);
    ft_lstadd_back(a, new); // 여기서 a=null일경우에 new를 처음으로 해주는 코드가있음
    (*arg_i) += 1;//이렇게 해야 발류가 올라감
    return (0);
}
