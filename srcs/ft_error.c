/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:21:07 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:17:18 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int nb, char **tab)
{
	if (nb == 0)
	{
		ft_putendl_fd("Error : Wrong params", 1);
		exit(EXIT_FAILURE);
	}
	else if (nb == 1)
	{
		ft_putendl_fd("Error : Map wall error", 1);
		ft_free(tab);
		exit(EXIT_FAILURE);
	}
	else if (nb == 2)
	{
		ft_putendl_fd("Error : Invalid char", 1);
		ft_free(tab);
		exit(EXIT_FAILURE);
	}
}

void	ft_error_2(int nb, char **tab)
{
	if (nb == 3)
	{
		ft_putendl_fd("Error : bro wtf is that map?", 1);
		ft_free(tab);
		exit(EXIT_FAILURE);
	}
	else if (nb == 4)
	{
		ft_putendl_fd("Error : Wrong nb of Starting-pos/Exit/Collectible", 1);
		ft_free(tab);
		exit(EXIT_FAILURE);
	}
}
