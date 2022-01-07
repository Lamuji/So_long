/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:24:10 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:12:17 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rect(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[j])
		{
			if (ft_strlen(str[i]) != ft_strlen(str[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_invalid_char(char **str, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((i > 0 && i < height - 1) && (j > 0 && j < width - 1))
			{
				if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'P'
					&& str[i][j] != 'C' && str[i][j] != 'E')
					return (1);
			}
		j++;
		}
	i++;
	}
	return (0);
}

int	check_wall(char **tab, size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < width)
		{		
			if (i == '0' || j == '0' || i == height - 1 || j == width - 1)
			{
				if (tab[i][j] != '1')
					return (1);
			}
		j++;
		}
	i++;
	}
	return (0);
}

int	arg_is_correct(int ac, char *str)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (str[i])
		{
			if (str[i] == '.')
			{
				if (str[i + 1] == 'b' && str[i + 2] == 'e'
					&& str[i + 3] == 'r' && !(str[i + 4]))
					return (1);
			}
			i++;
		}
	}
	return (0);
}
