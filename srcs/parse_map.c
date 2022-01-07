/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:21:10 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:21:38 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map *map)
{
	if (check_wall(map->tab, map->height, map->width) == 1)
		ft_error(1, map->tab);
	if (check_invalid_char(map->tab, map->height, map->width) == 1)
		ft_error(2, map->tab);
	if (check_map_rect(map->tab) == 1)
		ft_error_2(3, map->tab);
}
