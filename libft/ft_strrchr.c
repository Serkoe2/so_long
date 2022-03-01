/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:05:29 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/13 02:40:30 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char			*end;
	unsigned char	symb;

	symb = c;
	end = (char *)src + ft_strlen(src);
	if (symb == '\0')
		return (end);
	while (end-- != src)
	{
		if (*end == symb)
			return (end);
	}
	return (NULL);
}
