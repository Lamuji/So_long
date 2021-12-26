/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:21:07 by rfkaier           #+#    #+#             */
/*   Updated: 2021/12/26 18:37:41 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int nb, char **tab)
{
	if (nb == 0)
	{
		ft_putendl_fd("Error : Wrong params", 1);
		//free(tab);
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
		ft_putendl_fd("Error : invalid char", 1);
		ft_free(tab);
		exit(EXIT_FAILURE);
	}
	else if (nb == 3)
	{
		ft_putendl_fd("Error : bro wtf is that map?", 1);
		ft_free(tab);
		exit(EXIT_FAILURE);
	}
}
