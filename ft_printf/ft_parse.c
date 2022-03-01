/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:44:35 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 19:17:50 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char *str, va_list args)
{
	int		count;
	char	format;

	format = *(str + 1);
	count = 0;
	if (format == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (format == 's')
		count = ft_print_str(va_arg(args, char *));
	else if (format == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		count = ft_print_int(va_arg(args, int));
	else if (format == 'u')
		count = ft_print_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		count = ft_putchar('%');
	else
		count = ft_putchar(format);
	return (count);
}
