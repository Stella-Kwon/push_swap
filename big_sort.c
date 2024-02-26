/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:50:49 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/26 23:01:31 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int first_one_bit(t_stack *a)
{
    t_stack *max;
    int bits;
    int bit;
    int i;

    max = find_max_pointer(a); // protect 해줘야하나?
    bits = sizeof(max->index) * 8;
    printf("\n\nmax_index : %lld\n\n", max->index);
    // printf("\n\nmax_data: %lld\n\n", max->data);
    // printf("\n\nmax_bits : %d\n\n", bits);
    i = bits - 1; // because bit index starts from 0
    while (i >= 0)
    {
        bit = ((max->index) >> i) & 1;
        // printf("\n\n%dth : %ibit\n\n", i, bit);
        if (bit == 1)
            return (i);
        i--;
    }
    return (i);
}

t_stack *to_binary_sort(t_stack **a)
{
    int i;
    int j;
    int bit;
    int movements;
    t_stack *b;
    t_stack *a_tmp;
    t_stack *a_top;

    movements = 0;
    b = NULL;
    a_top = NULL;

    // maximum 크기의 숫자를 찾아서 왼쪽에서시작해서 오른쪽으로 가는데 1이나오는데서 멈춰서 몇개 비트있는지 체크한담에 넘겨주기.
    // printf("a : %lld\n", (*a)->data);
    j = 0;
    i = first_one_bit(*a);
    printf("\n\nthe start_i = %d\n\n", i);
    while (j <= i)
    {
        printf("\n\n\n------i : %d------\n\n\n", i);
        a_tmp = *a;
        while (a_tmp)
        {
            printf("\n\n\n-----data check-----\n\n\n");
            while (a_tmp)
            {
                printf("index : %lld\n", a_tmp->index);
                a_tmp = a_tmp->next;
            }
            a_tmp = *a;
            bit = ((a_tmp->index) >> j) & 1;
            printf("\n\n\n----a_tmp index:  %lld \n", a_tmp->index);
            printf("\n\n\n----a_tmp data :  %lld \n", a_tmp->data);
            printf("\n\n\n----a_data :  %lld \n", (*a)->data);
            printf("\n\n%dth : %ibit\n\n", i, bit);
            movements = move_bit_to_Bstack(bit, a, &b, movements, &a_top); //ra가 될경우에 무한루프에 빠질수있어.. *a가 끝나지 않을 수 있으니. 그래서 *a를 계속 움직이지말고 정확한 지점을 정해주기
            // a_tmp = (a_tmp)->next;  a_tmp의 b스택으로 넘어가면서 바로 null값이 나와서 안된다
            a_tmp = *a;//이렇게 해줘야ㅡ바뀌어진 a값이랑 맞아지면서 제대로된 index값도 확인하고 밑의 무한루프를 끊는 if문에서도 활용이 가능하다.
            // printf("a_top :  %lld \n", a_top->index);
            if (a_top && a_tmp == a_top)
            {
                // a_tmp = a_tmp->next;
                a_top = NULL;
                break;
            }
                
        }
        printf("\n\n\n------from b------\n\n\n");
        // *a = a_top;//확실히 해주기위해
        while (b)
        {
            if(*a)
                printf("a top;data :  %lld \n", (*a)->data);
            printf("b top;data :  %lld \n", b->data);
            printf("\n\n\n-----data check-----\n\n\n");
            a_tmp = *a;
            while (a_tmp)
            {
                printf("index : %lld\n", a_tmp->index);
                a_tmp = a_tmp->next;
            }
            printf("\n\n\n---------------------\n\n\n");
            ft_pa(a, &b);
            movements++;
            printf("\nmovements : %d\n", movements);
            }
        j++;
    }
    return(*a);
}

long long move_bit_to_Bstack(int bit, t_stack **a, t_stack **b, int movements, t_stack **a_top)
{
    if (bit == 1)
    {
        printf("\n\n\n------ft_ra------\n\n\n");
        if (!(*a_top))
        {
            *a_top = *a;
            printf("a_top :  %lld \n", (*a_top)->index);
        }
            
        ft_ra(a);
        printf("====> ra 다음 *a->index: %lld\n", (*a)->index);
        movements++;
        printf("\nmovements : %d\n", movements);
    }
    else if (bit == 0)
    {       
        printf("\n\n\n------ft_pb------\n\n\n");
        // if (*b)
        //     printf("*b->data : %lld \n\n", (*b)->data);
        ft_pb(a, b);
        printf("====> pb 다음 *b->index : %lld \n\n", (*b)->index);
        movements++;
        printf("\nmovements : %d\n", movements);
    }
    return (movements);
}

int big_sort(t_stack **a)
{
    if (pre_sort(a) == -1)
        return (-1);
    *a = to_binary_sort(a);
    return (0);
}



// int main()
// {
//     long long num;
//     num = 5;
//     to_binary(num);
//     return 0;
// }
