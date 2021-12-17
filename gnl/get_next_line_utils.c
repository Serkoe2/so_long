/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:19:08 by cchekov           #+#    #+#             */
/*   Updated: 2021/11/01 12:25:31 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*boof;
	int		i;
	int		j;
	
	boof = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!boof)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		boof[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		boof[i++] = s2[j++];
	boof[i] = '\0';
	return (boof);
}

size_t	ft_strlcpy_gnl(char *dest, char *src)
{
	unsigned int 	i;

	i = 0;
	while (src[i]){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}
