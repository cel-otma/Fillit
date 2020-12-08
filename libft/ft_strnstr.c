/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:00:33 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/02 17:18:27 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		if (needle[j] == haystack[i])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
		if (j == ft_strlen((char*)needle))
			return ((char*)haystack + (i - j));
	}
	return (NULL);
}
