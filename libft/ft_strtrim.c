/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:17:43 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/09 17:11:07 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	put(const char *s, char *s1, int i, int len)
{
	int			j;

	j = 0;
	while (i < len)
	{
		s1[j] = s[i];
		i++;
		j++;
	}
	s1[j] = '\0';
}

char			*ft_strtrim(char const *s)
{
	int			i;
	char		*s1;
	int			len;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ') && s[i])
		i++;
	while ((s[len - 1] == '\t' || s[len - 1] == '\n' || s[len - 1] == ' ') &&
			len >= 0)
		len--;
	if (len <= 0)
	{
		len = 1;
		i = 1;
	}
	if (!(s1 = (char*)malloc(sizeof(char) * ((len - i) + 1))))
		return (NULL);
	put(s, s1, i, len);
	return (s1);
}
