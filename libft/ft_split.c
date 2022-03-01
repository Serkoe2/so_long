/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:58:42 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/15 20:07:57 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_array(char **array, int count)
{
	count--;
	while (count >= 0)
	{
		free(array[count]);
		count--;
	}
	free(array);
}

static char	*append_array(char **array, char *str, int count)
{
	if (!str)
	{
		clear_array(array, count);
		return (NULL);
	}
	array[count] = str;
	return (array[count]);
}

static void	set_words(char **result, char const *s, char c)
{
	char			*find;
	size_t			len;
	unsigned int	count;

	count = 0;
	find = ft_strchr(s, c);
	while (find)
	{
		len = find - s;
		if (len != 0)
		{
			if (!append_array(result, ft_substr(s, 0, len), count))
				return ;
			count++ ;
		}
		s = s + len + 1;
		find = ft_strchr(s, c);
	}
	len = ft_strlen(s);
	if (len != 0)
		if (!append_array(result, ft_substr(s, 0, len), count++))
			return ;
	result[count] = NULL;
}

static int	count_words(char const *s, char c)
{
	char			*find;
	size_t			len;
	unsigned int	count;

	if (ft_strlen(s) == 0)
		return (0);
	if (c == '\0')
		return (1);
	count = 0;
	find = ft_strchr(s, c);
	while (find)
	{
		len = find - s;
		s = s + len + 1;
		if (len != 0)
			count++ ;
		find = ft_strchr(s, c);
	}
	if (ft_strlen(s) != 0)
		count++;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**result;
	unsigned int	count;

	if (!s)
		return (NULL);
	count = 0;
	count = count_words(s, c);
	result = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	if (count == 0)
		result[0] = NULL;
	else if (c == 0)
	{
		if (!append_array(result, ft_strdup(s), 0))
			return (NULL);
		result[1] = NULL;
	}
	else
		set_words(result, s, c);
	return (result);
}
