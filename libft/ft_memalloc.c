/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:07:35 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/19 15:49:52 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*v;
	int		i;

	v = NULL;
	i = 0;
	if (!(v = malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(v, size);
	return ((void*)v);
}
