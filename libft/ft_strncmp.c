/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 18:25:29 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/02 18:19:57 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cc1;
	unsigned char	*cc2;

	i = 0;
	cc1 = (unsigned char*)s1;
	cc2 = (unsigned char*)s2;
	while ((cc1[i] || cc2[i]) && n > i)
	{
		if (cc1[i] - cc2[i] != 0)
			return (cc1[i] - cc2[i]);
		i++;
	}
	return (0);
}
