/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 11:40:22 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/06 20:12:37 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_map *map, int y, int x)
{
	if (map->tab[y][x] == '0' || map->tab[y][x] == 'P')
		return (1);
	else if (map->tab[y][x] == 'E')
		return (2);
	else if (map->tab[y][x] == 'C')
		return (3);
	return (0);
}

void	move_down(t_map *map)
{
	if (map->tab[map->start_y + 1][map->start_x] == '0' || map->tab[map->start_y + 1][map->start_x] == 'C')
	{
		if (map->tab[map->start_y + 1][map->start_x] == 'C')
			map->collect--;
		map->start_y++;
		map->tab[map->start_y - 1][map->start_x] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
	}
	else if (map->tab[map->start_y + 1][map->start_x] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else 
			printf("You didn't take all the hearts\n");
	}
}

void	move_left(t_map *map)
{
	if (map->tab[map->start_y][map->start_x - 1] == '0' || map->tab[map->start_y][map->start_x - 1] == 'C')
	{
		if (map->tab[map->start_y][map->start_x - 1] == 'C')
			map->collect--;
		map->start_x--;
		map->tab[map->start_y][map->start_x + 1] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
	}
	else if (map->tab[map->start_y][map->start_x - 1] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else 
			printf("You didn't take all the hearts\n");
	}
}

void	move_right(t_map *map)
{
	if (map->tab[map->start_y][map->start_x + 1] == '0' || map->tab[map->start_y][map->start_x + 1] == 'C')
	{
		if (map->tab[map->start_y][map->start_x + 1] == 'C')
			map->collect--;
		map->start_x++;
		map->tab[map->start_y][map->start_x - 1] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
	}
	else if (map->tab[map->start_y][map->start_x + 1] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else 
			printf("You didn't take all the hearts\n");
	}
}

void	move_top(t_map *map)
{
	if (map->tab[map->start_y - 1][map->start_x] == '0' || map->tab[map->start_y - 1][map->start_x] == 'C')
	{
		if (map->tab[map->start_y - 1][map->start_x] == 'C')
			map->collect--;
		map->start_y--;
		map->tab[map->start_y + 1][map->start_x] = '0';
		map->tab[map->start_y][map->start_x] = 'P';
		map->move++;
	}
	else if (map->tab[map->start_y - 1][map->start_x] == 'E')
	{
		if (map->collect == 0)
			exit_game();
		else
			printf("You didn't take all the hearts\n");
	}
}
