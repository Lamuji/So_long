/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:52:50 by hkrifa            #+#    #+#             */
/*   Updated: 2021/12/23 20:02:10 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h> 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

/*# ifndef FD_MAX
#  define FD_MAX 255
# endif*/

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dst_size);
char	*ft_strdupgnl(char *s1);
char	*ft_strjoingnl(char *s1, char *s2);

#endif