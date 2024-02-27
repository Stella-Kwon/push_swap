/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suminkwon <suminkwon@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:04:45 by suminkwon         #+#    #+#             */
/*   Updated: 2024/02/27 15:54:58 by suminkwon        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t srclen;
    size_t i;

    srclen = ft_strlen(src);
    i = 0;
    if (dstsize == 0)
        return (srclen);
    while (i < (dstsize - 1) && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (srclen);
}

size_t ft_strlen(const char *s)
{
    int c;

    c = 0;
    if (!s)
        return (0);
    while (s[c] != '\0')
        c++;
    return (c);
}