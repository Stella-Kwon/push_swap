/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:56:26 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/15 23:01:04 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int arg, char **args)
{
    t_stack *a; // only the stack a will be returned
    t_stack *tmp;
    
    a = NULL; // value of a is null;
    // printf("a address:%p\n a value : %p\n", (void *)&a, (void *)a); //ptr는 주소를 담는다는것 기억해
    if (error_check(arg, args, &a) == -1) // &a로 보내야 포인터로 보내져 값이 바뀜 , 나는 error_check 안에 있는 insert에서만 해주면 되지않나 생각했는데 호출되는 함수에서부터 받아와져야한다는것을 놓친것!
        return (0);
    printf("\n\n\n-----Link_NODE-----\n\n\n");
    tmp = a;//has to have it as printing nodes out a has moved to the end and got NULL
    while (a)
    {
        printf("stack value : %lld\n", a->data);
        a = a->next;
    }
    a = tmp;
    if (is_sorted(a) == -1)
    {
        // if (arg > 5)
        //     big_sort();
        // else
        //     small_sort();
        printf("sort now");
    }
    ft_free(&a);
    // if (!a)
    //     printf("\n\n\n-----TEH END-----\n");
    // printf("nothing\n\n\n");
    return 0;
}