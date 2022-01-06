/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:35:59 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/06 19:59:44 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_map *map)
{
	map->img_ground = mlx_xpm_file_to_image(map->mlx, map->ground, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, map->pix_x, map->pix_y);
	map->img_wall = mlx_xpm_file_to_image(map->mlx, map->wall, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_wall, map->pix_x, map->pix_y);
}

void	put_ground(t_map *map)
{
	map->img_ground = mlx_xpm_file_to_image(map->mlx, map->ground, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, map->pix_x, map->pix_y);
}

void	put_collec(t_map *map)
{
	map->img_ground = mlx_xpm_file_to_image(map->mlx, map->ground, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, map->pix_x, map->pix_y);
	map->img_collec = mlx_xpm_file_to_image(map->mlx, map->collec, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_collec, map->pix_x, map->pix_y);
}

void	put_character(t_map *map)
{
	map->img_ground = mlx_xpm_file_to_image(map->mlx, map->ground, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, map->pix_x, map->pix_y);
	if (map->pos == 1)
		map->img_character = mlx_xpm_file_to_image(map->mlx, "img/charup.xpm", &map->img_width, &map->img_height);
	else if (map->pos == 2)
		map->img_character = mlx_xpm_file_to_image(map->mlx, "img/charright.xpm", &map->img_width, &map->img_height);
	else if (map->pos == 3)
		map->img_character = mlx_xpm_file_to_image(map->mlx, "img/charleft.xpm", &map->img_width, &map->img_height);
	else
		map->img_character = mlx_xpm_file_to_image(map->mlx, "img/char.xpm", &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_character, map->pix_x, map->pix_y);
}

void	put_exit(t_map *map)
{
	map->img_ground = mlx_xpm_file_to_image(map->mlx, map->ground, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ground, map->pix_x, map->pix_y);
	map->img_exit = mlx_xpm_file_to_image(map->mlx, map->exit, &map->img_width, &map->img_height);
	mlx_put_image_to_window(map->mlx, map->win, map->img_exit, map->pix_x, map->pix_y);
}
