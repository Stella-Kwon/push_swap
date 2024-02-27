/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:56:26 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 15:35:19 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int arg, char **args)
{
    t_stack *a; // only the stack a will be returned
    t_stack *tmp;
    long long i;

    i = 0;
    a = NULL; // value of a is null;
    // printf("a address:%p\n a value : %p\n", (void *)&a, (void *)a); //ptr는 주소를 담는다는것 기억해
    if (error_check(arg, args, &a, &i) == -1) // &a로 보내야 포인터로 보내져 값이 바뀜 , 나는 error_check 안에 있는 insert에서만 해주면 되지않나 생각했는데 호출되는 함수에서부터 받아와져야한다는것을 놓친것!
        return (0);
    printf("\n\n\n-----Link_NODE-----\n\n\n");
    tmp = a;//has to have it as printing nodes out a has moved to the end and got NULL
    while (tmp)
    {
        printf("stack value : %lld\n", tmp->data);
        tmp =tmp->next;
    }
    /*
    check the a stack is not empty
    -> checked it with error_check()
    */
    arg = i + 1;
    if (is_sorted(a) == -1)
    {
        if (arg <= 6)
            small_sort(&a, arg);
        // else if (arg)
        else   
        {
            if(big_sort(&a) == -1)
                return (-1);
        } 
    }
    //a = tmp;// 이렇게 하면 제대로 안나옴 순서가
    tmp = a;
    printf("\n\n\n-----After BINARY_SORTED_Lists-----\n\n\n");
    while (tmp)
    {
        printf("sorted value : %lld\n", tmp->data);
        tmp = (tmp)->next;
    }
    ft_free(&a);
    if (!a)
        printf("\n\n\n-----TEH END-----\n");
    printf("nothing\n\n\n");
    return 0;
}



// int main(int arg, char **args)
// {
//     t_stack *a;
//     t_stack *tmp;

//     a = NULL;
//     if (error_check(arg, args, &a) == -1)
//         return (0);
//     printf("\n\n\n-----Link_NODE-----\n\n\n");
//     tmp = a;
//     while (a)
//     {
//         printf("stack value : %lld\n", a->data);
//         a = a->next;
//     }
//     a = tmp;
//     printf("\n\n\n-----Link_NODE-----\n\n\n");
//     printf("%d\n", is_sorted(a));
//     if (is_sorted(a) == -1)
//     {
//         printf("sort now");
//         if (arg < 5)
//             small_sort(&a);
//     }
//     a = tmp;
//     printf("\n\n\n-----SORTED_Lists-----\n\n\n");
//     while (a)
//     {
//         printf("sorted value : %lld\n", a->data);
//         a = a->next;
//     }
//     a = tmp;
//     printf("\n\n\n-----SORTED index-----\n\n\n");
//     while (a)
//     {
//         printf("sorted index : %lld\n", a->index);
//         a = a->next;
//     }
//     ft_free(&a);
//     return 0;
// }