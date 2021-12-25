/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:25:48 by haroun            #+#    #+#             */
/*   Updated: 2021/12/23 20:28:04 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && (dest_len + i + 1) < dst_size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dst_size < dest_len)
		return (dst_size +src_len);
	return (dest_len + src_len);
}

char	*ft_strdupgnl(char *s1)
{
	char	*tmp;
	int		i;

	i = ft_strlen(s1);
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (0);
	i = 0;
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*newstr;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdupgnl(s2));
	if (!s2)
		return (ft_strdupgnl(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, s1_len + 1);
	free(s1);
	ft_strlcat(newstr + (s1_len), s2, s2_len + 1);
	return (newstr);
}
