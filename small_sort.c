/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:42:38 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 01:17:34 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void up_to_four(t_stack **a, t_stack **b)
{
    long long max;

    max = find_max(*a);
    while (*a)
    {
        if (max == (*a)->data)
        {
            ft_pb(a, b);
            printf("max : %lld\n", max);
            break;
        }
        ft_ra(a);
        printf("*a = %lld\n", (*a)->data);
    }
    printf("a = %lld\n", (*a)->data);
    if (is_sorted(*a) == -1)
        up_to_three(a);
    ft_pa(a, b);
    ft_ra(a);
}

void up_to_five(t_stack **a, t_stack **b)
{
    long long min;
    
    min = find_min(*a);
    printf("min : %lld\n", min);
    while(*a)
    {
        if (min == (*a)->data)
        {
            ft_pb(a, b);
            printf("min = %lld\n", (*a)->data);
            break;
        }
        ft_ra(a);
        printf("*a = %lld\n", (*a)->data);
    }
    up_to_four(a, b);
    ft_pa(a, b);
}

void up_to_three(t_stack **a)
{
    if (find_min(*a) == (*a)->data) // comparing to the first elements.
    {
        ft_rra(a);
        ft_sa(a);
    }
    else if (find_max(*a) == (*a)->data)
    {
        ft_ra(a);
        if (is_sorted(*a) == -1)
            ft_sa(a);
    }
    else
    {
        // if (find_index(*a, find_max(*a)) == 1) pointer로 함수를 바로 넣어주고있기 때문에 parameter없이 함수이름만 적어주면된다. 그리고 물론 longlong max 구해서 넣어줘도 되지만 일단 이렇게 함수를 넣어줌
        // 위에꺼로 하면 매개변수로 넣어준 함수때매 방지해야할게 많아져서 그냥 long long 숫자로 넣어줌
        if (find_index(*a, find_max(*a)) == 1) // check if max number is in the second order
            ft_rra(a);
        else
            ft_sa(a);
    }
}

void small_sort(t_stack **a, int arg)
{
    t_stack *b;

    b = NULL;
    if (arg <= 4)
        up_to_three(a);
    else if (arg == 5)
        up_to_four(a, &b);
    else if (arg == 6)
        up_to_five(a, &b);
}