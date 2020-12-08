/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:08:13 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/09 17:09:33 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		getcountspaces(char const *str, char c)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
		{
			if (str[i + 1] != c && str[i + 1] != '\0')
				count++;
			i++;
			if (str[i] == '\0')
			{
				i--;
				break ;
			}
		}
		i++;
	}
	if (str[0] != c && str[0] != '\0')
		return (count + 1);
	return (count);
}

static	int		getsize(int i, char const *str, char c)
{
	int			size;

	size = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i] != c && str[i])
	{
		size++;
		i++;
	}
	return (size);
}

static	char	**set_at(char const *mn, char **tab, int i, char c)
{
	int			j;

	j = 0;
	while (mn[i])
	{
		while (mn[i] == c && mn[i])
			i++;
		if (mn[i] != '\0')
		{
			if (!(tab[j] = (char*)malloc((getsize(i, mn, c) + 1)
			* sizeof(char))))
				return (NULL);
			tab[j] = ft_strsub(mn, i, getsize(i, mn, c));
			i += getsize(i, mn, c);
			j++;
		}
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(array = (char**)malloc((getcountspaces(s, c) + 1) * sizeof(char*))))
		return (NULL);
	if (!(array[0] = (char*)malloc((getsize(i, s, c) + 1) * sizeof(char))))
		return (NULL);
	array = set_at(s, array, i, c);
	if (array == NULL)
		return (NULL);
	array[getcountspaces(s, c)] = 0;
	return (array);
}
