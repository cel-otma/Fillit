/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-imra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:23:01 by ael-imra          #+#    #+#             */
/*   Updated: 2019/04/10 14:37:32 by ael-imra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fraiche;

	if (lst == NULL)
		return (NULL);
	if (!(fraiche = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	fraiche = f(lst);
	if (lst->next != NULL)
		fraiche->next = ft_lstmap(lst->next, f);
	return (fraiche);
}
