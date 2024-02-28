/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_args_to_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:46:55 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 13:52:10 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	while (*lst != NULL)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
}

int	insert_args(long long atoi_i, t_stack **a, long long *arg_i)
{
	t_stack	*new;

	new = NULL;
	if (!(*a))
		new = ft_lstnew(atoi_i);
	else if ((*a))
		new = ft_lstnew(atoi_i);
	if (!new)
	{
		ft_free(a);
		return (-1);
	}
	ft_lstadd_back(a, new);
	(*arg_i) += 1;
	return (0);
}
