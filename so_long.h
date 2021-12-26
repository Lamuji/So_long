/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:56:16 by rfkaier           #+#    #+#             */
/*   Updated: 2021/12/26 19:11:11 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H


#include <stdio.h>
#include "Libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef  struct	s_map
{
	char **tab;
	size_t		width;
	size_t		height;
}				t_map;

char	*ft_strjjoin(char *s1, char *s2);
void	ft_error(int nb, char **tab);
int		check_invalid_char(char **str, size_t height, size_t width);
int		check_wall(char **tab, size_t height, size_t width);
int		arg_is_correct(int ac, char *str);
void	ft_free(char **map);
int		check_map_rect(char **str);
void	parse_map(t_map map);
char **	get_tab(char **tab, char **av);





// #include <minilibx/mlx.h>
// #include <minilibx/mlx_int.h>
// #include <minilibx/mlx_opengl.h>
// #include <minilibx/mlx_png.h>

#endif