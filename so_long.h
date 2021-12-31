/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:56:16 by rfkaier           #+#    #+#             */
/*   Updated: 2021/12/31 02:21:41 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
#define SO_LONG_H


#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <mlx.h>
#include <fcntl.h>

typedef  struct	s_map
{
	void		*img;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	char 		**tab;
	size_t		width;
	size_t		height;
	char		*wall;
	char		*character;
	char		*ground;
	char		*collec;
	char		*exit;
	int			win_width;
	int			win_height;
	
}				t_map;

typedef struct s_data
{
	void	*img;
	char 	*addr;
	int		bpp;
	int		lenline;
	int endian;
}				t_data;

char	*ft_strjjoin(char *s1, char *s2);
void	ft_error(int nb, char **tab);
int		check_invalid_char(char **str, size_t height, size_t width);
int		check_wall(char **tab, size_t height, size_t width);
int		arg_is_correct(int ac, char *str);
void	ft_free(char **map);
int		check_map_rect(char **str);
void	parse_map(t_map map);
char 	**get_tab(char **tab, char **av);
void	open_win(t_map map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif