/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:25:26 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/15 23:01:31 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *a) // checking only : no need to pass **, no modify
{
    t_stack *tmp;

    while (a)
    {
        // printf ("\na : %lld\n", a->data);
        tmp = a->next;
        while (tmp)
        {
            // printf("\nnext argument : %lld\n", tmp->data);
            if (a->data >= tmp->data) 
                return (-1);
            tmp = tmp->next;
        }
        a = a->next;
    }
    return (0);
}