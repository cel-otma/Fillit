/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:06:52 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/09 17:10:00 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		itoa1(unsigned int nb, char *str, int j, int count)
{
	str[count] = '\0';
	count--;
	while (count >= 0)
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
		count--;
		if (j == -1 && count == 0)
		{
			str[0] = '-';
			count--;
		}
	}
}

char				*ft_itoa(int n)
{
	char			*str;
	unsigned int	i;
	int				count;
	int				j;
	unsigned int	nb;

	count = 0;
	j = 0;
	nb = n;
	if (n <= 0)
	{
		nb = -n;
		count++;
		j = -1;
	}
	i = nb;
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	itoa1(nb, str, j, count);
	return (str);
}
