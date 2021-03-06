/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:12:09 by cchekov           #+#    #+#             */
/*   Updated: 2022/03/09 23:00:15 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*boof;
	size_t	i;
	size_t	j;	

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
