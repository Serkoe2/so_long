/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:08:00 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/13 16:26:55 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*get_string(size_t sub_len, unsigned int start, size_t len)
{
	char	*result;

	if (sub_len == 0 || start >= sub_len)
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (sub_len < len)
		len = sub_len;
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_memset(result, 'A', len);
	return (result);
}	

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			len_substr;
	char			*result;

	if (!s)
		return (NULL);
	len_substr = ft_strlen(s);
	result = get_string(len_substr, start, len);
	if (!result || ft_strlen(result) == 0)
		return (result);
	i = 0;
	s = s + start;
	if (len_substr < len)
		len = len_substr;
	while (len--)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
