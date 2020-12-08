/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verrifier_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:19:03 by cel-otma          #+#    #+#             */
/*   Updated: 2019/07/28 16:19:31 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count(char *line, int size, char caract)
{
	int i;
	int caractere;
	int incre;

	i = 0;
	caractere = 0;
	incre = 0;
	while (i < size)
	{
		if (line[i] == caract)
			caractere++;
		if (line[i] == '\n' && incre != 4 && i < 20)
			return (0);
		if (incre == 4)
			incre = -1;
		incre++;
		i++;
	}
	return (caractere);
}

void	remplir(char *str, char dest[4][4])
{
	int i;
	int j;
	int m;

	i = 0;
	m = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			while (str[m] != '\n')
			{
				dest[i][j] = str[m];
				m++;
				j++;
			}
			m++;
		}
		i++;
	}
}

int		verrifier_posi(char ch[4][4])
{
	int x;
	int y;
	int count;

	count = 0;
	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (ch[x][y] == '#')
			{
				if (x > 0 && ch[x - 1][y] == '#')
					count++;
				if (x < 3 && ch[x + 1][y] == '#')
					count++;
				if (y > 0 && ch[x][y - 1] == '#')
					count++;
				if (y < 3 && ch[x][y + 1] == '#')
					count++;
			}
	}
	if (count != 6 && count != 8)
		return (0);
	return (1);
}

int		verrifier(int fd, int *tetriminos)
{
	char	line[21];
	char	dest[4][4];
	int		size;

	while ((size = read(fd, line, 21)) == 21)
	{
		if (count(line, 21, '\n') != 5 || count(line, 21, '.') != 12
				|| count(line, 21, '#') != 4)
			return (-1);
		remplir(line, dest);
		if (verrifier_posi(dest) == 0)
			return (-1);
		*tetriminos = *tetriminos + 1;
		if (*tetriminos > 25)
			return (-1);
	}
	if (count(line, size, '\n') != 4 || count(line, size, '.') != 12
			|| count(line, size, '#') != 4)
		return (-1);
	remplir(line, dest);
	if (verrifier_posi(dest) == 0)
		return (-1);
	return (1);
}
