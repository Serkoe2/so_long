/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:06:28 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/15 16:52:01 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*overlap;
	void	*result;

	if (!dest && !src)
		return (NULL);
	if (dest > src + n || src > dest + n)
	{
		return (ft_memcpy(dest, src, n));
	}
	else
	{
		overlap = ft_calloc(n, sizeof(unsigned char));
		overlap = ft_memcpy(overlap, src, n);
		result = ft_memcpy(dest, overlap, n);
		free(overlap);
		return (result);
	}
}
