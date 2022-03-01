/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:07:21 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/13 16:33:57 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	int				end;
	size_t			s1_len;
	size_t			set_len;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	start = 0;
	end = s1_len;
	if (!s1_len || !set_len)
		return (ft_strdup((char *)s1));
	while (ft_strchr(set, *(s1 + start)) && start < s1_len)
		start++;
	if (start == s1_len)
		return (ft_strdup(""));
	while (ft_strrchr(set, *(s1 + end - 1)) && end >= 0)
		end--;
	return (ft_substr(s1, start, end - start));
}
