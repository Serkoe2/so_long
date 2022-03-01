/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:56:14 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 22:56:15 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_itoa(unsigned long long num, int base, int cas)
{
	char	*str;
	int		count;
	int		temp;

	count = ft_count_num(num, base);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	if (!cas)
		cas = 87;
	else
		cas = 55;
	str[count] = '\0';
	while (num != 0)
	{
		temp = num % base;
		if (temp < 10)
			str[count - 1] = temp + 48;
		else
			str[count - 1] = temp + cas;
		num = num / base;
		count--;
	}
	return (str);
}
