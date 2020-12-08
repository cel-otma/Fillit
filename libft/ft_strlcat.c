/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 14:48:30 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/09 12:48:51 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	dstl;
	int		i;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	dstl = lendst;
	if (size < dstl)
		return (size + lensrc);
	while (src[i] && lendst + 1 < size)
	{
		dst[lendst] = src[i];
		i++;
		lendst++;
	}
	dst[lendst] = '\0';
	return (dstl + lensrc);
}
