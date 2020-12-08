/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-otma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:18:04 by cel-otma          #+#    #+#             */
/*   Updated: 2019/07/28 16:18:37 by cel-otma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit target_file");
		return (0);
	}
	if (ft_fillit(argv[1]) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	return (0);
}
