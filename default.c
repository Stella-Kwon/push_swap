/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skwon2 <skwon2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:22:41 by skwon2            #+#    #+#             */
/*   Updated: 2024/02/10 18:28:27 by skwon2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_check(int arg, char **args)
{
    int i;
    i =  0;
    
    // if (args == NULL)
    //     return;
    while (i < arg)
    {
        if (sizeof(args[i]) > sizeof(int) | sizeof(args[i]) != sizeof(int))
            write(1, "ERROR", 6);
    }
}

int main(int arg, char **args)
{
    error_check(arg,args);
    return 0;
}