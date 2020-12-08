/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:38:27 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/05 13:37:14 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
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
