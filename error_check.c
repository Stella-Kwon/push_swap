/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:22:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/02/28 18:24:20 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	write_error(void)
{
	int	length;

	length = write(2, "Error\n", 6);
	if (length == -1)
		write(2, "Error\n", 6);
	return (-1);
}

int	check_integer(int arg, char *args, t_stack **a, long long *arg_i)
{
	long long	atoi_i;
	long long	atoi_j;
	char		*j;

	atoi_i = ft_atoi_m(args);
	if (!args[0] || atoi_i == -1 || sizeof(atoi_i) > sizeof(long long))
		return (write_error());
	j = args + 1;
	while (*j)
	{
		atoi_j = ft_atoi_m(j);
		if (atoi_j != -1 && atoi_i == atoi_j)
			return (write_error());
		j++;
	}
	if (insert_args(atoi_i, a, arg_i) == -1)
		return (write_error());
	return (1);
}

int	arg_is_two(int arg, char **args, t_stack **a, long long *arg_i)
{
	char	**str_arg;
	int		i;

	i = 0;
	str_arg = NULL;
	str_arg = ft_split(args[1], ' ');
	if (!str_arg[i])
		return (write_error());
	while (str_arg[i])
	{
		if (check_integer(arg, str_arg[i], a, arg_i) == -1)
		{
			all_free(str_arg);
			return (-1);
		}
		i++;
	}
	all_free(str_arg);
	return (1);
}

int	error_check(int arg, char **args, t_stack **a, long long *arg_i)
{
	long long	i;

	i = 1;
	if (arg < 2)
		return (-1);
	if (arg == 2)
	{
		if (arg_is_two(arg, args, a, arg_i) == -1)
			return (-1);
		return (1);
	}
	while (i < arg)
	{
		if (check_integer(arg, args[i], a, arg_i) == -1)
			return (-1);
		i++;
	}
	if (!a)
		return (write_error());
	return (1);
}
