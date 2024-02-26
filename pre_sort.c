/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:42:38 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 00:25:42 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *copy_stack(t_stack *a)
{
    t_stack *new;
    t_stack *head;
    t_stack *prev_node;
    if (!a)
        return (NULL); // already covered but in case
    head = NULL;
    prev_node = NULL;
    while (a)
    {
        new = (t_stack *)malloc(sizeof(t_stack));
        if (!new)
        {
            ft_free(&head); // 이전노드 있으묜
            ft_free(&a);
            return (NULL);
        }
        new->data = a->data;
        // new->index = a->index;
        // new->next = a->next; this is not true as new->next should follow the following node of new of a
        new->next = NULL;
        if (!head)
            head = new;            // in order to return the first address of t_stack
        else                       // this way of course it should has the previou node! if head is empty then no previous node needed
            prev_node->next = new; // first node -> next = the seconde node.
        prev_node = new;           // when the first approach of this code will point to the first node
        a = a->next;
    }
    return (head);
}

static t_stack *merge(t_stack *left, t_stack *right)
{
    t_stack *result;
    t_stack *dummy_head;
    t_stack *current_node;

    dummy_head = (t_stack *)malloc(sizeof(t_stack)); // NULL 로 하면 에러
    if (!dummy_head)
        return NULL;
    current_node = dummy_head;
    printf("\n\n\n-----merge-----\n\n\n");
    // printf("left: %lld -> \n", left->data);
    // printf("right : %lld -> \n", right->data);
    while (left && right)
    {
        if (left->data < right->data)
        {
            current_node->next = left;
            printf("left : %lld -> ", left->data);
            left = left->next; // i++;
        }
        else
        {
            current_node->next = right;
            printf("right : %lld -> ", right->data);
            right = right->next; // i++;
        }
        current_node = current_node->next; // 현재 정렬해준 노드를 가르키게된다.
        // current_node->next 는 일단 값이 없는 상태가된다 NULL. 선언되지않은 상태라서.
    }
    if (left)
        current_node->next = left;
    else if (right)
        current_node->next = right;
    while (current_node) // current_node->next->data하면 안돼
    {
        if (!current_node->next) // current_node의 다음 노드가 없으면 루프 종료
            printf(" end\n");
        break;
        printf("current_node->next->data : %lld ->", current_node->next->data);
        current_node = current_node->next;
    }
    result = dummy_head->next;
    free(dummy_head);
    return (result);
}

t_stack *divide_merge_sort(t_stack *copy)
{
    t_stack *head;
    t_stack *mid;
    t_stack *left_lists;
    t_stack *right_lists;
    t_stack *tmp_mid;

    // if(!copy)
    //     return(NULL);//더미노드 눌일때 -> merge 값 NULL
    head = copy;
    if (!copy->next) // should protect !*copy from copy_stack -> NULL // !(*copy)->next 는 더이상 나눈 다음의 수가없다는거, 1개 남았으니 끝
        return (head);
    /*
    if (!copy || !copy->next) 조건은 copy가 NULL이거나 copy의 다음 노드가 없는 경우를 확인합니다. 그러나 copy가 NULL이라면 함수가 호출되지 않기 때문에 이 조건은 필요하지 않습니다. 따라서 !copy->next만 확인하면 됩니다.
    */
    mid = find_middle_node(copy);
    tmp_mid = mid->next;
    mid->next = NULL;
    mid = tmp_mid;

    printf("mid : %lld\n", mid->data);
    left_lists = divide_merge_sort(head); // 역참조 필요없어 왜냐 포인터 반환하잖아
    right_lists = divide_merge_sort(mid);

    return (merge(left_lists, right_lists)); //-> sort된 result를 돌려주기 //포인터를 리턴해주기때문에 dereferencing 해주지 않아도 돼
}

void put_index(t_stack **sort)
{
    t_stack *tmp;

    tmp = *sort;
    long long i;

    i = 0;
    while (tmp)
    {
        (tmp)->index = i;
        (tmp) = (tmp)->next;
        i++;
    }
}

void pass_index_(t_stack **sort, t_stack **a)
{
    t_stack *a_tmp;
    t_stack *sort_tmp;
    printf("sort : %lld\n", (*sort)->data);
    // if (!a_tmp)
    // {
    //     ft_free(sort);
    //     ft_free(a);
    //     return (write_error());
    // }//already covered from top before i call it
    sort_tmp = *sort;
    a_tmp = *a;
    while (a_tmp)
    {
        if ((a_tmp)->data == (sort_tmp)->data)
        {
            (a_tmp)->index = (sort_tmp)->index;
            (a_tmp) = (a_tmp)->next;
        }
        else
        {
            (sort_tmp) = (sort_tmp)->next;
            if (!sort_tmp)
                sort_tmp = *sort;
        }
    }
    // printf("sort->data : %lld\n", (*sort)->data);
    printf("\n\n\n-----A_stack index-----\n\n\n");
    a_tmp = *a;
    while (a_tmp)
    {
        printf("stack_a index : %lld\n", a_tmp->index);
        a_tmp = a_tmp->next;
    }
    sort_tmp = *sort;
    while (sort_tmp)
    {
        printf("sort index : %lld\n", sort_tmp->index);
        sort_tmp = sort_tmp->next;
    }
    ft_free(sort);
}

int pre_sort(t_stack **a) // a has been protected already
{
    t_stack *copy;
    t_stack *sort;
    t_stack *tmp;

    copy = copy_stack(*a);
    if (!copy)
        return (write_error()); // took care of free in copy stack
    // tmp = copy;
    // while (tmp)
    // {
    //     printf("copy data : %lld\n", tmp->data);
    //     tmp = tmp->next;
    // }
    sort = divide_merge_sort(copy); // merge함수자체가 리턴값이라서 그것에 문제가 있으면 실행되지않음
    tmp = sort;
    printf("\n\n\n-----SORTED data-----\n\n\n");
    while (tmp)
    {
        printf("sorted data : %lld\n", tmp->data);
        tmp = tmp->next;
    }
    if (!sort)
    {
        // ft_free(copy);
        // ft_free(&sort); // already list order has been changed
        ft_free(a);
        return (write_error());
    }
    tmp = sort;
    put_index(&sort);
    printf("\n\n\n-----SORTED index-----\n\n\n");
    while (tmp)
    {
        printf("sorted index : %lld\n", tmp->index);
        tmp = tmp->next;
    }
    pass_index_(&sort, a);
    // ft_free(&sort);
    return (0);
}
