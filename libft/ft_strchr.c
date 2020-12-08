/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:14:14 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/02 16:44:11 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;
	char	cc;

	ch = (char*)s;
	i = 0;
	cc = (char)c;
	while (ch[i] != cc && ch[i])
		i++;
	if (ch[i] == '\0' && cc != '\0')
		return (NULL);
	return (ch + i);
}
