/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:17:35 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:33:42 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(void)
{
	exit(0);
}

int	deal_key(int keycode, t_map *map)
{
	if (keycode == ESC)
		exit_game();
	else if (keycode == W)
	{
		map->pos = 1;
		move_top(map);
	}
	else if (keycode == D)
	{
		map->pos = 2;
		move_right(map);
	}
	else if (keycode == A)
	{
		map->pos = 3;
		move_left(map);
	}
	else if (keycode == S)
	{
		move_down(map);
		map->pos = 4;
	}
	printf("Number of movements : %d\n", map->move);
	return (0);
}

void	valid_char_pos(t_map *map)
{
	while (map->tab[map->y])
	{
		map->x = 0;
		while (map->tab[map->y][map->x])
		{
			if (map->tab[map->y][map->x] == 'P')
			{
				map->perso++;
				map->start_y = map->y;
				map->start_x = map->x;
			}
			else if (map->tab[map->y][map->x] == 'E')
				map->exit_e++;
			else if (map->tab[map->y][map->x] == 'C')
				map->collect++;
			map->x++;
		}
		map->y++;
	}
	if (map->perso < 1 || map->exit_e < 1)
		ft_error_2(4, map->tab);
}

void	display_win(t_map *map)
{
	valid_char_pos(map);
	map->y = 0;
	map->pix_y = 0;
	while (map->tab[map->y])
	{
		map->x = 0;
		map->pix_x = 0;
		while (map->tab[map->y][map->x])
		{
			put_ground(map);
			if (map->tab[map->y][map->x] == '1')
				put_wall(map);
			else if (map->tab[map->y][map->x] == 'C')
				put_collec(map);
			else if (map->tab[map->y][map->x] == 'P')
				put_character(map);
			else if (map->tab[map->y][map->x] == 'E')
				put_exit(map);
			map->x++;
			map->pix_x += 32;
		}
		map->pix_y += 32;
		map->y++;
	}
}

void	display_win_2(t_map *map)
{
	map->y = 0;
	map->pix_y = 0;
	while (map->tab[map->y])
	{
		map->x = 0;
		map->pix_x = 0;
		while (map->tab[map->y][map->x])
		{
			if (map->tab[map->y][map->x] == '0')
				put_ground(map);
			else if (map->tab[map->y][map->x] == 'C')
				put_collec(map);
			else if (map->tab[map->y][map->x] == 'P')
				put_character(map);
			map->x++;
			map->pix_x += 32;
		}
		map->pix_y += 32;
		map->y++;
	}
}
