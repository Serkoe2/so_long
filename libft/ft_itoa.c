/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 15:05:52 by cchekov           #+#    #+#             */
/*   Updated: 2021/05/11 14:36:44 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_numb(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static	char	*to_str(int n, int count, char *numb)
{
	int		i;

	if (n < 0)
	{
		numb[0] = '-';
		n = n * -1;
	}
	i = count;
	while (n)
	{
		numb[--count] = n % 10 + '0';
		n = n / 10;
	}
	numb[i] = '\0';
	return (numb);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*numb;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = count_numb(n);
	numb = ft_calloc(count + 1, 1);
	if (!numb)
		return (NULL);
	numb = to_str(n, count, numb);
	return (numb);
}
