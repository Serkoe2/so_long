/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchekov <cchekov@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:14:22 by cchekov           #+#    #+#             */
/*   Updated: 2021/07/17 19:20:58 by cchekov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_parse(const char *str, va_list args);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long p);
char	*ft_printf_itoa(unsigned long long num, int base, int cas);
int		ft_count_num(unsigned long long num, int base);
int		ft_print_int(int num);
int		ft_print_uint(unsigned int num);
int		ft_print_hex(unsigned int num, char cas);

#endif