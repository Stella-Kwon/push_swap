/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:56:26 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 15:45:07 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int arg, char **args)
{
	t_stack		*a;
	long long	arg_i;

	arg_i = 0;
	a = NULL;
	if (error_check(arg, args, &a, &arg_i) == -1)
		return (-1);
	arg = arg_i + 1;
	if (is_sorted(a) == -1)
	{
		if (arg <= 6)
			small_sort(&a, arg);
		else
		{
			if (big_sort(&a) == -1)
				return (-1);
		}
	}
	ft_free(&a);
	return (0);
}
