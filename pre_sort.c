/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:42:38 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 15:58:54 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *copy_stack(t_stack *a)
{
    t_stack *new;
    t_stack *head;
    t_stack *prev_node;
    if (!a)
        return (NULL);
    head = NULL;
    prev_node = NULL;
    while (a)
    {
        new = (t_stack *)malloc(sizeof(t_stack));
        if (!new)
        {
            ft_free(&head);
            ft_free(&a);
            return (NULL);
        }
        new->data = a->data;
        new->next = NULL;
        if (!head)
            head = new; 
        else            
            prev_node->next = new;
        prev_node = new;
        a = a->next;
    }
    return (head);
}

static t_stack *merge(t_stack *left, t_stack *right)
{
    t_stack *result;
    t_stack *dummy_head;
    t_stack *current_node;

    dummy_head = (t_stack *)malloc(sizeof(t_stack));
    if (!dummy_head)
        return NULL;
    current_node = dummy_head;
    while (left && right)
    {
        if (left->data < right->data)
        {
            current_node->next = left;
            left = left->next;
        }
        else
        {
            current_node->next = right;
            right = right->next;
        }
        current_node = current_node->next;
    }
    if (left)
        current_node->next = left;
    else if (right)
        current_node->next = right;
    while (current_node)
    {
        if (!current_node->next)
            break;
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

    head = copy;
    if (!copy->next)
        return (head);
    mid = find_middle_node(copy);
    tmp_mid = mid->next;
    mid->next = NULL;
    mid = tmp_mid;
    left_lists = divide_merge_sort(head);
    right_lists = divide_merge_sort(mid);
    return (merge(left_lists, right_lists));
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
    ft_free(sort);
}

int pre_sort(t_stack **a)
{
    t_stack *copy;
    t_stack *sort;

    copy = copy_stack(*a);
    if (!copy)
        return (write_error());
    sort = divide_merge_sort(copy);
    if (!sort)
    {
        ft_free(a);
        return (write_error());
    }
    put_index(&sort);
    pass_index_(&sort, a);
    return (0);
}
