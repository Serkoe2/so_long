/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 13:12:09 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/03 10:56:53 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*boof;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	boof = (char *)ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!boof)
		return (NULL);
	ft_strlcpy(boof, s1, s1_len + 1);
	ft_strlcpy(boof + s1_len, s2, s2_len + 1);
	return (boof);
}
