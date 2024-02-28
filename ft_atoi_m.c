/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:16:22 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/28 18:30:34 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	overflow_check(long long res, int sign, char str)
{
	if (sign * res + (str - 48) > LLONG_MAX / 10)
		return (-1);
	if (sign * res + (str - 48) < LLONG_MIN / 10)
		return (-1);
	res = res * 10 + (str - 48);
	return (res);
}

static long long	check_only_integer(const char *str, long long i, int sign)
{
	long long	res;

	res = 0;
	while (str[i])
	{
		if (str[i])
		{
			if (str[i] >= 48 && str[i] <= 57)
			{
				res = overflow_check(res, sign, str[i]);
				i++;
			}
			else if (str[i] < 48 || str[i] > 57 || res == -1)
				return (-1);
		}
	}
	return (res);
}

long long	ft_atoi_m(const char *str)
{
	long long	i;
	long long	res;
	int			sign;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] > 8 && str[i] <= 13) || str[i] == 32)
		i++;
	while ((str[i] == 45 || str[i] == 43) && str[i + 1] > 47 && str[i + 1] < 58)
	{
		if (str[i] == 45)
			sign = -1;
		i++;
	}
	res = check_only_integer(str, i, sign);
	if (res == -1)
		return (-1);
	return (sign * res);
}
