/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:08:28 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/15 17:07:12 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	find_in(const char *src, const char *find)
{
	while (*find)
	{
		if (*src++ != *find++)
			return ('0');
	}
	return ('1');
}

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	find_len;
	char	q;

	q = *src;
	find_len = ft_strlen(find);
	if (find_len == 0)
		return ((char *)src);
	while (n-- >= find_len && *src)
	{
		if (*src == *find)
		{
			if (find_in(src, find) == '1')
				return ((char *)src);
		}
		src++;
	}
	return (NULL);
}
