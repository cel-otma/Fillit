/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:36:33 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/18 14:19:47 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ch;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	ch = (unsigned char*)s;
	while (i < n)
	{
		if (ch[i] == cc)
			return ((void*)s + i);
		i++;
	}
	return (NULL);
}
