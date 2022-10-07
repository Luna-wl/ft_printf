/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:14:33 by sky               #+#    #+#             */
/*   Updated: 2022/10/02 12:36:39 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr(int num);
int		ft_putnbr2(unsigned int num, unsigned int base, char flag);
int		ft_puthex(size_t num);
int		ft_putstr(char *s);
int		check_flag(const char *fmt, va_list args);
int		check_bo(const char *fmt, va_list args);
int		ft_putnbr_bo(int num, char flag);
int		ft_atoi(const char *str);
int		ft_putstr_bo(char *s, int wide);
int		ft_putnbr2_bo(unsigned int num, char flag);

#endif