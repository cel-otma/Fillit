/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:08:39 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/01 16:52:44 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ch;
	unsigned char	*c;

	i = 0;
	ch = (unsigned char*)s1;
	c = (unsigned char*)s2;
	while (i < n)
	{
		if (ch[i] != c[i])
			return ((int)ch[i] - c[i]);
		i++;
	}
	return (0);
}
