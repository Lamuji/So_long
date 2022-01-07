/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:56:16 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:32:53 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# include <stdio.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "../minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	void	*img;
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		pix_x;
	int		pix_y;
	char	**tab;
	size_t	width;
	size_t	height;
	char	*wall;
	char	*character;
	char	*ground;
	char	*collec;
	char	*exit;
	void	*img_ground;
	void	*img_collec;
	void	*img_character;
	void	*img_exit;
	void	*img_wall;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		start_x;
	int		start_y;
	int		collect;
	int		perso;
	int		exit_e;
	int		move;
	int		pos;
}				t_map;

char	*ft_strjjoin(char *s1, char *s2);
void	ft_error(int nb, char **tab);
void	ft_error_2(int nb, char **tab);
int		check_invalid_char(char **str, size_t height, size_t width);
int		check_wall(char **tab, size_t height, size_t width);
int		arg_is_correct(int ac, char *str);
void	ft_free(char **map);
int		check_map_rect(char **str);
void	parse_map(t_map *map);
char	**get_tab(char **tab, char **av);
void	display_win(t_map *map);
void	display_win_2(t_map *map);
void	move_top(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	put_texture(t_map *map);
void	put_wall(t_map *map);
void	put_ground(t_map *map);
void	put_collec(t_map *map);
void	put_character(t_map *map);
void	put_exit(t_map *map);
int		deal_key(int keycode, t_map *map);
int		exit_game(void);
#endif