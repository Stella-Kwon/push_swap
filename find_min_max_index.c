/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:03:05 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/25 19:21:58 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long find_min(t_stack *a_b)
{
    long long min;

    min = a_b->data;
    while (a_b)
    {
        if (min > a_b->data)
            min = a_b->data;
        a_b = a_b->next;
    }
    return (min);
}

long long find_max(t_stack *a_b)
{
    long long max;

    max = a_b->data;
    while (a_b)
    {
        if (max < a_b->data)
            max = a_b->data;
        a_b = a_b->next;
    }
    return (max);
}

t_stack *find_max_pointer(t_stack *a_b)
{
    long long max;
    t_stack *max_pointer;

    // if (!a_b) // 빈 스택에 대한 예외 처리
    //     return NULL;
    max_pointer = a_b;
    max = a_b->data;
    while (a_b)
    {
        if (max < a_b->data)
        {
            max = a_b->data;
            max_pointer = a_b;
            
        }
        a_b = a_b->next;
    }
    printf("max pointer: %lld\n", max_pointer->data);
    return (max_pointer);
}

int find_index(t_stack *a_b, long long data)
{
    int i = 0;

    while (a_b)
    {
        if (a_b->data == data)
        {
            // printf(" i : %d\n", i);
            return i;
        }
        // printf("data index : %lld \n", data);
        // printf("a_b index : %lld \n", a_b->data);
        a_b = a_b->next;
        i++;
    }
    return -1;
}

t_stack *find_middle_node(t_stack *copy)
{
    t_stack *jump_one;
    t_stack *jump_two;

    jump_one = copy;
    jump_two = copy;
    while (jump_two->next && jump_two->next->next)//이렇게 두개 다 해줘야 명확히 다음게 없어도, 있어도 다다음게 없을떄 둘다 대비해서 스톱해준다.
    {
        jump_one = jump_one->next;
        jump_two = jump_two->next->next;
    }
    //left가 언제나 한개 더 많게 나옴. 홀수 일때
    return (jump_one);
}

// int find_index(t_stack *a_b, long long (*find)(t_stack *a_b))
// {
//     int i;

//     i = 0;
//     if (!a_b || !find)
//         return (-1); // a_b이미 이 전 단계에서 방지했는데 find라는 함수 파라미터때매 해줘야하는데 이거까지 해야하나..? 
//     while (a_b)
//     {
//         if (a_b->data != find(a_b))
//         {
//             a_b = a_b->next;
//             i++;
//         }
//     }
//     return (i);
// }

