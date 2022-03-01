/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:09:31 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/13 02:39:15 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	symb;

	symb = c;
	if (symb == '\0')
		return ((char *)(src + ft_strlen(src)));
	while (*src != '\0')
	{
		if (*src == symb)
			return ((char *)src);
		src++;
	}
	return (NULL);
}
