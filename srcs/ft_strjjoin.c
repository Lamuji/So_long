/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 18:20:39 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/07 18:20:40 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		len_s2;
	char		*dest;

	if (s1 == NULL)
		s1 = ft_calloc(1, 1);
	i = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + len_s2 + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	len_s2 = -1;
	while (s2[++len_s2])
	{
		dest[i] = s2[len_s2];
		i++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}
