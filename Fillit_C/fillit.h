/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:17:20 by cel-otma          #+#    #+#             */
/*   Updated: 2019/07/28 16:17:42 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct	s_point{
	int x;
	int y;
}				t_point;
typedef struct	s_tabpoint
{
	int		x;
	int		y;
	t_point tab[4];
}				t_tabpoint;

char			**resized_map(char **tab, int *size_map, t_tabpoint *point);
void			free_map(char **tab, int size_map);
void			affi(char **tab, int size);
int				count(char *line, int size, char caract);
void			remplir(char *str, char dest[4][4]);
int				verrifier_posi(char ch[4][4]);
int				verrifier(int fd, int *tetriminos);
char			**create_map(int size_map);
void			decalage(char str[4][4]);
void			remplir_tab(int size, int fd, int i);
void			backtracking(int size, char tab1[26 * 4][4], char alpha,
		int i);
int				size_tab(int size);
void			placement(t_tabpoint *point, char tab[4][4]);
void			incre(t_tabpoint *point, int size);
void			incre2(int *i, char *alpha, t_tabpoint *point);
int				delete_(t_tabpoint *poi, char **tab, char alpha,
		char tab1[4][4]);
int				index_j(int *po, t_tabpoint poi);
int				charge_tableau(t_tabpoint *poi, char **tab, int size,
		char alpha);
int				ft_fillit(char *av);

#endif
