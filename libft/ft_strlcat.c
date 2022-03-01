/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:07:47 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/13 15:27:29 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	dest_len;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (n <= dest_len)
		return (n + src_len);
	dest += dest_len;
	n = n - dest_len - 1;
	while (n-- && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (src_len + dest_len);
}
