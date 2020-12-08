/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:30 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/18 13:25:41 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*frais;

	if (!(frais = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		frais->content = NULL;
		frais->content_size = 0;
	}
	else
	{
		frais->content = ft_strnew(content_size);
		ft_memcpy(frais->content, content, content_size);
		frais->content_size = content_size;
	}
	frais->next = NULL;
	return (frais);
}
