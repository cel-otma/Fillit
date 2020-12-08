/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 11:25:00 by ael-imra          #+#    #+#             */
/*   Updated: 2019/07/28 11:39:16 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**resized_map(char **tab, int *size_map, t_tabpoint *point)
{
	int		i;
	char	**tab2;

	free_map(tab, *size_map);
	i = -1;
	*size_map = *size_map + 1;
	tab2 = (char **)malloc((*size_map + 1) * sizeof(char *));
	while (++i < *size_map)
	{
		tab2[i] = ft_strnew(*size_map);
		tab2[i] = ft_memset(tab2[i], '.', *size_map);
	}
	tab2[i] = NULL;
	point->x = 0;
	point->y = 0;
	return (tab2);
}

void		free_map(char **tab, int size_map)
{
	int		i;

	i = -1;
	while (++i < size_map)
		free(tab[i]);
	free(tab);
}

void		affi(char **tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	free_map(tab, size);
}

int			ft_fillit(char *av)
{
	int		fd;
	int		terminos;

	terminos = 0;
	fd = open(av, O_RDONLY);
	if (verrifier(fd, &terminos) == -1)
		return (-1);
	close(fd);
	fd = open(av, O_RDONLY);
	remplir_tab(terminos + 1, fd, 0);
	close(fd);
	return (1);
}
