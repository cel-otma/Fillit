/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:09:06 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/19 15:48:14 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ch;
	char const	*c;

	i = 0;
	ch = (char*)dst;
	c = (char const*)src;
	while (i < n)
	{
		ch[i] = c[i];
		i++;
	}
	return (dst);
}
