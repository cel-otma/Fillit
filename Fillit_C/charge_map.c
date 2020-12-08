/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:27:40 by ael-imra          #+#    #+#             */
/*   Updated: 2019/07/28 11:38:00 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		delete_(t_tabpoint *poi, char **tab, char alpha, char tab1[4][4])
{
	int i;
	int j;
	int m;

	i = -1;
	placement(poi, tab1);
	while (tab[++i] != NULL)
	{
		j = -1;
		while (tab[i][++j])
		{
			m = 0;
			if (tab[i + poi->tab[m].x][j + poi->tab[m].y] == alpha)
			{
				m = -1;
				while (++m < 4)
					tab[i + poi->tab[m].x][j + poi->tab[m].y] = '.';
				poi->x = i;
				poi->y = j;
				return (1);
			}
		}
	}
	return (0);
}

int		index_j(int *po, t_tabpoint poi)
{
	int j;

	if (*po == 0)
	{
		j = poi.y - 1;
		*po = *po + 1;
	}
	else
		j = -1;
	return (j);
}

int		charge_tableau(t_tabpoint *poi, char **tab, int size, char alpha)
{
	int i;
	int j;
	int m;
	int po;

	i = poi->x - 1;
	po = 0;
	while (tab[++i] != NULL)
	{
		j = index_j(&po, *poi);
		while (tab[i][++j])
		{
			m = 0;
			while (m < 4 && i + poi->tab[m].x < size && j + poi->tab[m].y < size
					&& tab[i + poi->tab[m].x][j + poi->tab[m].y] == '.')
				m++;
			if (m == 4)
			{
				while (--m >= 0)
					tab[i + poi->tab[m].x][j + poi->tab[m].y] = alpha;
				return (1);
			}
		}
	}
	return (0);
}
