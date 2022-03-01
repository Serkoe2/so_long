/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 17:33:27 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 17:33:58 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_num(unsigned long long num, int base)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num = num / base;
		count++;
	}
	return (count);
}
