/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:40:22 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:19:46 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_map *map)
{
	if (map->tab[map->start_y + 1][map->start_x] == '0'
		|| map->tab[map->start_y + 1][map->start_x] == 'C')
	{
		if (map->tab[map->start_y + 1][map->start_x] == 'C')
			map->collect--;
		map->start_y++;
		map->tab[map->start_y - 1][map->start_x] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
		display_win_2(map);
	}
	else if (map->tab[map->start_y + 1][map->start_x] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else
			printf("Hearts remaining on map !\n");
	}
}

void	move_left(t_map *map)
{
	if (map->tab[map->start_y][map->start_x - 1] == '0'
		|| map->tab[map->start_y][map->start_x - 1] == 'C')
	{
		if (map->tab[map->start_y][map->start_x - 1] == 'C')
			map->collect--;
		map->start_x--;
		map->tab[map->start_y][map->start_x + 1] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
		display_win_2(map);
	}
	else if (map->tab[map->start_y][map->start_x - 1] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else
			printf("Hearts remaining on map !\n");
	}
}

void	move_right(t_map *map)
{
	if (map->tab[map->start_y][map->start_x + 1] == '0'
		|| map->tab[map->start_y][map->start_x + 1] == 'C')
	{
		if (map->tab[map->start_y][map->start_x + 1] == 'C')
			map->collect--;
		map->start_x++;
		map->tab[map->start_y][map->start_x - 1] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
		display_win_2(map);
	}
	else if (map->tab[map->start_y][map->start_x + 1] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else
			printf("Hearts remaining on map !\n");
	}
}

void	move_top(t_map *map)
{
	if (map->tab[map->start_y - 1][map->start_x] == '0'
		|| map->tab[map->start_y - 1][map->start_x] == 'C')
	{
		if (map->tab[map->start_y - 1][map->start_x] == 'C')
			map->collect--;
		map->start_y--;
		map->tab[map->start_y + 1][map->start_x] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
		display_win_2(map);
	}
	else if (map->tab[map->start_y - 1][map->start_x] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else
			printf("Hearts remaining on map !\n");
	}
}
