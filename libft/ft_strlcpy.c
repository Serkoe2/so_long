/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:08:42 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/15 21:13:38 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	src_len;

	if (!dest || !src)
		return (0);
	src_len = ft_strlen(src);
	if (src_len == 0)
	{
		*dest = '\0';
		return (src_len);
	}
	if (n == 0)
		return (src_len);
	n--;
	while (n-- && *src)
		*(dest)++ = *(src)++;
	*dest = '\0';
	return (src_len);
}
