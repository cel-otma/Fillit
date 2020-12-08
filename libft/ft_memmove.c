/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:58:29 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/19 16:36:32 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ch;
	unsigned char	*c;

	ch = (unsigned char*)dst;
	c = (unsigned char*)src;
	if (dst > src)
	{
		while (len--)
			ch[len] = c[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
