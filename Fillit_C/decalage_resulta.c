/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decalage_resulta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:26:25 by ael-imra          #+#    #+#             */
/*   Updated: 2019/07/28 11:37:50 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		position(char str[4][4], int i, int pos)
{
	int			j;
	t_point		point;

	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (str[i][j] != '.')
			{
				if (pos == 0)
				{
					point.x = i;
					point.y = j;
					pos = 1;
				}
				else
				{
					if (point.x > i)
						point.x = i;
					if (point.y > j)
						point.y = j;
				}
			}
	}
	return (point);
}

char		**create_map(int size_map)
{
	int		i;
	char	**tab;

	i = -1;
	tab = (char **)malloc((size_map + 1) * sizeof(char *));
	while (++i < size_map)
	{
		tab[i] = ft_strnew(size_map);
		tab[i] = ft_memset(tab[i], '.', size_map);
	}
	tab[i] = NULL;
	return (tab);
}

void		decalage(char str[4][4])
{
	int		i;
	int		j;
	t_point point;

	point = position(str, -1, 0);
	i = point.x;
	while (i < 4)
	{
		j = point.y;
		if (point.x == 0 && point.y == 0)
			break ;
		while (j < 4)
		{
			str[i - point.x][j - point.y] = str[i][j];
			str[i][j] = '.';
			j++;
		}
		i++;
	}
}

void		remplir_tab(int size, int fd, int i)
{
	char	tab[26 * 4][4];
	char	buff[20];
	int		j;
	int		m;

	while (read(fd, buff, 20) == 20)
	{
		m = 0;
		while (m < 20)
		{
			j = -1;
			while (++j < 4)
			{
				tab[i][j] = buff[m];
				m++;
			}
			m++;
			i++;
		}
		decalage(tab + (i - 4));
		read(fd, buff, 1);
	}
	backtracking(size, tab, 'A', 0);
}
