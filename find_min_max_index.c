/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:03:05 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 16:32:37 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	find_min(t_stack *a_b)
{
	long long	min;

	min = a_b->data;
	while (a_b)
	{
		if (min > a_b->data)
			min = a_b->data;
		a_b = a_b->next;
	}
	return (min);
}

long long	find_max(t_stack *a_b)
{
	long long	max;

	max = a_b->data;
	while (a_b)
	{
		if (max < a_b->data)
			max = a_b->data;
		a_b = a_b->next;
	}
	return (max);
}

t_stack	*find_max_pointer(t_stack *a_b)
{
	long long	max;
	t_stack		*max_pointer;

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
	return (max_pointer);
}

int	find_index(t_stack *a_b, long long data)
{
	int	i;

	i = 0;
	while (a_b)
	{
		if (a_b->data == data)
			return (i);
		a_b = a_b->next;
		i++;
	}
	return (-1);
}

t_stack	*find_middle_node(t_stack *copy)
{
	t_stack	*jump_one;
	t_stack	*jump_two;

	jump_one = copy;
	jump_two = copy;
	while (jump_two->next && jump_two->next->next)
	{
		jump_one = jump_one->next;
		jump_two = jump_two->next->next;
	}
	return (jump_one);
}
