/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:42:38 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 15:43:09 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_to_four(t_stack **a, t_stack **b)
{
	long long	max;

	max = find_max(*a);
	while (*a)
	{
		if (max == (*a)->data)
		{
			ft_pb(a, b);
			break ;
		}
		ft_ra(a);
	}
	if (is_sorted(*a) == -1)
		up_to_three(a);
	ft_pa(a, b);
	ft_ra(a);
}

void	up_to_five(t_stack **a, t_stack **b)
{
	long long	min;

	min = find_min(*a);
	while (*a)
	{
		if (min == (*a)->data)
		{
			ft_pb(a, b);
			break ;
		}
		ft_ra(a);
	}
	up_to_four(a, b);
	ft_pa(a, b);
}

void	up_to_three(t_stack **a)
{
	if (find_min(*a) == (*a)->data)
	{
		ft_rra(a);
		ft_sa(a);
	}
	else if (find_max(*a) == (*a)->data)
	{
		ft_ra(a);
		if (is_sorted(*a) == -1)
			ft_sa(a);
	}
	else
	{
		if (find_index(*a, find_max(*a)) == 1)
			ft_rra(a);
		else
			ft_sa(a);
	}
}

void	small_sort(t_stack **a, int arg)
{
	t_stack	*b;

	b = NULL;
	if (arg <= 4)
		up_to_three(a);
	else if (arg == 5)
		up_to_four(a, &b);
	else if (arg == 6)
		up_to_five(a, &b);
}
