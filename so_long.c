/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:57:30 by rfkaier           #+#    #+#             */
/*   Updated: 2021/12/25 19:34:50 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen1(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

void	ft_free(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

int	main(int ac, char **av)
{
	t_map	map;
	char *line;
	int fd;
	size_t	i;
	int j;
	int r;
	char buffer[2];

	if ((arg_is_correct(ac, av[1])) == 0)
	{
		ft_putendl_fd("Error : Wrong params", 1);
		exit(EXIT_FAILURE);
	}
	r = 1;
	
	i = 0;
	j = 0;
	map.height = 1;
	line = NULL;
	fd = open(av[1], O_RDONLY);
	while (r > 0)
	{
		r = read(fd, &buffer, 1);
		buffer[r] = '\0';
		line = ft_strjjoin(line, buffer);
	}
	map.tab = ft_split(line, '\n');
	free(line);
	map.width = ft_strlen(map.tab[i]);
	map.height = ft_strlen1(map.tab);
	// while (map.tab[i])
	// {
	// 	if (ft_strlen(map.tab[i]) != map.width || ft_strlen(map.tab[i]) == map.height)
	// 	{
	// 		ft_error(3,map.tab);
	// 		i++;
	// 	}
	// }
	if (check_wall(map.tab, map.height, map.width) == 1)
	 	ft_error(1, map.tab);
	if (check_invalid_char(map.tab, map.height, map.width) == 1)
	  	ft_error(2, map.tab);
	ft_free(map.tab);
	return (0);
}
