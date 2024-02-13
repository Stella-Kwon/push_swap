/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:22:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/02/13 15:57:10 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(void)
{
	int	length;

	length = write(1, "ERROR\n", 7);
	if (length == -1)
		// write(1, "WRITE_ERROR\n", 13);
		write(1, "ERROR\n", 7);
}

static long long	overflow_check(long long res, int sign, char str)
{
	if (sign * res + (str - 48) > LLONG_MAX / 10)
		return (LLONG_MAX);
	if (sign * res + (str - 48) < LLONG_MIN / 10)
		return (LLONG_MIN);
	res = res * 10 + (str - 48); // before it gets overflowed you need to check by LLONG_MAX/10
	return (res);
}

static long long	check_res(const char *str)
{
	int			i;
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
	if (!str[i] || (str[i] < 48 || str[i] > 57))
		return (-1);
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = overflow_check(res, sign, str[i]);
		i++;
	}
	return (sign * res);
}

long long	ft_atoi(const char *str)
{
	long long	result;

	result = check_res(str);
	return (result);
}

void	error_check(int arg, char **args)
{
	int		i;
	int		j;
	// char	*emp;
	int		atoi_i;
	int		atoi_j;
	
	i = 1;
	// emp = "";
	//if (args[1] == emp) ->  will only compare the addresses of it, not the contents.
	if ( arg <= 1 )
		return (write_error()); // this is woring because write_error is void func.
	while (i < arg) //&& j < arg)
	{
		atoi_i = ft_atoi(args[i]);
		//atoi_j = ft_atoi(args[j]); // this can be on here as j can be above arg , also you cannot put it on the while loop as (i < arg && j < arg) this cannot make i to be at the end, and (i < arg || j < arg) this doesn't meet both conditions so cannot make it work
		if (!args[i][0] || (atoi_i != -1 && sizeof(atoi_i) > sizeof(int)))
		return (write_error());
		// while (atoi_j != -1 && atoi_i != atoi_j && j < arg) // this one is not enough
		j = i + 1;
		while (j < arg)
		{
			atoi_j = ft_atoi(args[j]);
			if (atoi_j != -1 && atoi_i == atoi_j)
				return (write_error());
			j++;
		}
		i++;
	}
}

int main(int arg, char **args)
{
	error_check(arg,args);
	return 0;
}