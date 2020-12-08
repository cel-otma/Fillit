/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:06:39 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/09 12:50:06 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ch;
	int		i;

	ch = NULL;
	i = 0;
	if ((int)size >= 0)
	{
		if (!(ch = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while ((int)size >= 0)
		{
			ch[i] = '\0';
			i++;
			size--;
		}
	}
	return (ch);
}
