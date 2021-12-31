/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:17:35 by rfkaier           #+#    #+#             */
/*   Updated: 2021/12/31 02:58:37 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->lenline + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

int	deal_key(int keycode)
{
	if (keycode == 53)
		exit(0);
	return 0;
}


void	put_wall(t_map map)
{
	map.img = mlx_xpm_file_to_image(map.mlx, map.ground, &map.win_width, &map.win_height);
	mlx_put_image_to_window(map.mlx, map.win, map.img, map.x, map.y);
	map.img = mlx_xpm_file_to_image(map.mlx, map.wall, &map.win_width, &map.win_height);
	mlx_put_image_to_window(map.mlx, map.win, map.img, map.x, map.y);
}

void	put_ground(t_map map)
{
	map.img = mlx_xpm_file_to_image(map.mlx, map.ground, &map.win_width, &map.win_height);
	mlx_put_image_to_window(map.mlx, map.win, map.img, map.x, map.y);
}

void	put_collec(t_map map)
{
	map.img = mlx_xpm_file_to_image(map.mlx, map.ground, &map.win_width, &map.win_height);
	mlx_put_image_to_window(map.mlx, map.win, map.img, map.x, map.y);
	map.img = mlx_xpm_file_to_image(map.mlx, map.collec, &map.win_width, &map.win_height);
	mlx_put_image_to_window(map.mlx, map.win, map.img, map.x, map.y);
}

void	put_character(t_map map)
{
	map.img = mlx_xpm_file_to_image(map.mlx, map.ground, &map.win_width, &map.win_height);
	mlx_put_image_to_window(map.mlx, map.win, map.img, map.x, map.y);
	map.img = mlx_xpm_file_to_image(map.mlx, map.character, &map.win_width, &map.win_height);
	mlx_put_image_to_window(map.mlx, map.win, map.img, map.x, map.y);
}

// void	put_exit(t_map map)
// {
// 	map.img = mlx_xpm_file_to_image(map.mlx, map.ground, &map.win_width, &map.win_height);
// 	mlx_put_image_to_window(map.mlx, map.ground, map.img, 0, 0);
// 	map.img = mlx_xpm_file_to_image(map.mlx, map.exit, &map.win_width, &map.win_height);
// 	mlx_put_image_to_window(map.mlx, map.collec, map.exit, 0, 0);
// }

void	open_win(t_map map)
{
	int i = 0;
	map.mlx = mlx_init();
	map.y = 0;
	while (map.tab[i + map.y])
	{
		int j = 0;
		map.x = 0;
		while (map.tab[j + map.x])
		{
			if(map.tab[i + map.y][j + map.x] == '1')
				put_wall(map);
			else if (map.tab[i + map.y][j + map.x] == '0')
				put_ground(map);
			else if(map.tab[i + map.y][j + map.x] == 'C')
				put_collec(map);
			else if(map.tab[i + map.y][j + map.x] == 'P')
				put_character(map);
			// else if (map.tab[i][j] == 'E')
			// 	put_exit(map);
			map.x += 32;
			j++;
		}
		map.y += 32;
		i++;
	}
	// map.wall = "tree.xpm";
	
	//mlx_put_image_to_window(map.mlx, map.win, imag, 0, 0);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_loop(map.mlx);
}
