/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:42:38 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 15:39:40 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_stack **sort)
{
	t_stack		*tmp;
	long long	i;

	tmp = *sort;
	i = 0;
	while (tmp)
	{
		(tmp)->index = i;
		(tmp) = (tmp)->next;
		i++;
	}
}

void	pass_index_(t_stack **sort, t_stack **a)
{
	t_stack	*a_tmp;
	t_stack	*sort_tmp;

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

int	pre_sort(t_stack **a)
{
	t_stack	*copy;
	t_stack	*sort;

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
