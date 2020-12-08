/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resulta.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:27:08 by ael-imra          #+#    #+#             */
/*   Updated: 2019/07/28 11:38:54 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			size_tab(int size)
{
	int	i;

	i = 1;
	while (1)
	{
		if (i * i >= size * 4)
			break ;
		i++;
	}
	return (i);
}

void		placement(t_tabpoint *point, char tab[4][4])
{
	int		i;
	int		j;
	int		m;

	i = -1;
	m = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tab[i][j] != '.')
			{
				point->tab[m].x = i;
				point->tab[m].y = j;
				m++;
			}
	}
}

void		incre(t_tabpoint *point, int size)
{
	if (point->y >= size)
	{
		point->y = 0;
		point->x++;
	}
	else
		point->y++;
}

void		incre2(int *i, char *alpha, t_tabpoint *point)
{
	*i = *i + 4;
	*alpha = *alpha + 1;
	point->x = 0;
	point->y = 0;
}

void		backtracking(int size, char tab1[26 * 4][4], char alpha, int i)
{
	char		**tab;
	t_tabpoint	point;
	int			size_map;

	point.x = 0;
	point.y = 0;
	size_map = size_tab(size);
	tab = create_map(size_map);
	while (i < size * 4)
	{
		placement(&point, tab1 + i);
		if (charge_tableau(&point, tab, size_map, alpha) == 1)
			incre2(&i, &alpha, &point);
		else if (i == 0)
			tab = resized_map(tab, &size_map, &point);
		else
		{
			i = i - 4;
			alpha--;
			delete_(&point, tab, alpha, tab1 + i);
			incre(&point, size_map);
		}
	}
	affi(tab, size_map);
}
