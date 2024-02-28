/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:50:49 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 17:07:46 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	first_one_bit(t_stack *a)
{
	t_stack	*max;
	int		bits;
	int		bit;
	int		i;

	max = find_max_pointer(a);
	bits = sizeof(max->index) * 8;
	i = bits - 1;
	while (i >= 0)
	{
		bit = ((max->index) >> i) & 1;
		if (bit == 1)
			return (i);
		i--;
	}
	return (i);
}

t_stack	*to_binary_sort(t_stack **a)
{
	int		i;
	int		j;
	t_stack	*b;

	b = NULL;
	j = 0;
	i = first_one_bit(*a);
	while (j <= i)
	{
		move_to_b_stack(a, &b, &j);
		while (b)
			ft_pa(a, &b);
		j++;
	}
	return (*a);
}

void	move_to_b_stack(t_stack **a, t_stack **b, int *j)
{
	t_stack	*a_tmp;
	t_stack	*a_top;
	int		bit;

	a_top = NULL;
	a_tmp = *a;
	while (a_tmp)
	{
		bit = ((a_tmp->index) >> (*j)) & 1;
		if (bit == 1)
		{
			if (!(a_top))
				a_top = *a;
			ft_ra(a);
		}
		else if (bit == 0)
			ft_pb(a, b);
		a_tmp = *a;
		if (a_top && a_tmp == a_top)
		{
			a_top = NULL;
			break ;
		}
	}
}

int	big_sort(t_stack **a)
{
	if (pre_sort(a) == -1)
		return (-1);
	*a = to_binary_sort(a);
	return (0);
}
