/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:12:54 by rfkaier           #+#    #+#             */
/*   Updated: 2021/12/26 18:42:56 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map map)
{
	if (check_wall(map.tab, map.height, map.width) == 1)
	 	ft_error(1, map.tab);
	if (check_invalid_char(map.tab, map.height, map.width) == 1)
	  	ft_error(2, map.tab);
	if (check_map_rect(map.tab) == 1)
		ft_error(3, map.tab);
}
