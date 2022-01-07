/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:57:30 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:33:05 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen1(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

char	**get_tab(char **tab, char **av)
{
	char	*line;
	int		fd;
	int		r;
	char	buffer[2];

	r = 1;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl_fd("file doesn't exist", 2);
		exit(EXIT_FAILURE);
	}
	while (r > 0)
	{
		r = read(fd, &buffer, 1);
		buffer[r] = '\0';
		line = ft_strjjoin(line, buffer);
	}
	tab = ft_split(line, '\n');
	if (!(tab))
		exit(EXIT_FAILURE);
	free(line);
	return (tab);
}

void	init_struct(t_map *map)
{
	map->mlx = mlx_init();
	map->wall = "img/wall.xpm";
	map->character = "img/char.xpm";
	map->collec = "img/collec.xpm";
	map->ground = "img/ground.xpm";
	map->exit = "img/exit.xpm";
	map->win_width = map->width * 32;
	map->win_height = map->height * 32;
	map->win = mlx_new_window
		(map->mlx, map->win_width, map->win_height, "SO_LONG");
	map->y = 0;
	map->perso = 0;
	map->collect = 0;
	map->exit_e = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->move = 0;
	map->pos = 0;
}

int	main(int ac, char **av)
{
	t_map	map;
	int		i;

	i = 0;
	if ((arg_is_correct(ac, av[1])) == 0)
	{
		ft_putendl_fd("Error : Wrong params", 2);
		exit(EXIT_FAILURE);
	}
	map.tab = get_tab(map.tab, av);
	map.width = ft_strlen(map.tab[i]);
	map.height = ft_strlen1(map.tab);
	parse_map(&map);
	init_struct(&map);
	display_win(&map);
	mlx_hook(map.win, 2, 0, deal_key, &map);
	mlx_hook(map.win, 17, 0, exit_game, &map);
	mlx_loop(map.mlx);
	ft_free(map.tab);
	return (0);
}
