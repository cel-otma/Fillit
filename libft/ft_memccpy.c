/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:14:35 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/09 12:45:40 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ch;
	unsigned char	*c1;
	size_t			i;

	i = 0;
	ch = (unsigned char*)dst;
	c1 = (unsigned char*)src;
	while (i < n)
	{
		ch[i] = c1[i];
		if (ch[i] == (unsigned char)c)
			return ((dst) + i + 1);
		i++;
	}
	return (NULL);
}
