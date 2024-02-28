/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_divide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:59:23 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 17:13:38 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*free_both(t_stack **head, t_stack **a)
{
	ft_free(head);
	ft_free(a);
	return (NULL);
}

t_stack	*copy_stack(t_stack *a)
{
	t_stack	*new;
	t_stack	*head;
	t_stack	*prev_node;

	if (!a)
		return (NULL);
	head = NULL;
	prev_node = NULL;
	while (a)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return (free_both(&head, &a));
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

static void	check_bigger(t_stack **left, t_stack **right, t_stack **present)
{
	if ((*left)->data < (*right)->data)
	{
		(*present)->next = (*left);
		(*left) = (*left)->next;
	}
	else
	{
		(*present)->next = (*right);
		(*right) = (*right)->next;
	}
	(*present) = (*present)->next;
}

static t_stack	*merge(t_stack *left, t_stack *right)
{
	t_stack	*result;
	t_stack	*dummy_head;
	t_stack	*current_node;

	dummy_head = (t_stack *)malloc(sizeof(t_stack));
	if (!dummy_head)
		return (NULL);
	current_node = dummy_head;
	while (left && right)
		check_bigger(&left, &right, &current_node);
	if (left)
		current_node->next = left;
	else if (right)
		current_node->next = right;
	while (current_node)
	{
		if (!current_node->next)
			break ;
		current_node = current_node->next;
	}
	result = dummy_head->next;
	free(dummy_head);
	return (result);
}

t_stack	*divide_merge_sort(t_stack *copy)
{
	t_stack	*head;
	t_stack	*mid;
	t_stack	*left_lists;
	t_stack	*right_lists;
	t_stack	*tmp_mid;

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
