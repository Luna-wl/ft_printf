/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:07:28 by wluedara          #+#    #+#             */
/*   Updated: 2022/10/08 14:49:02 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	check_bo2(const char *fmt, va_list args)
// {
// 	int	len;
// 	int	wide;

// 	len = 0;
// 	wide = 0;
// 	if (*fmt == 's')
// 		len += ft_putstr_bo(va_arg(args, char *), 1);
// 	else
// 	{
// 		wide = ft_atoi(fmt);
// 		fmt++;
// 		len += ft_putstr_bo(va_arg(args, char *), wide);
// 	}
// 	return (len);
// // }

// int	check_bo(const char *fmt, va_list args)
// {
// 	int	len;

// 	len = 0;
// 	if (*fmt == 's')
// 		len += ft_putstr(va_arg(args, char *));
// 	else if (*fmt == 'd' || *fmt == 'i')
// 		len += ft_putnbr_bo(va_arg(args, int), ' ');
// 	else if (*fmt == 'x')
// 		len += ft_putnbr2_bo(va_arg(args, unsigned int), 'x');
// 	else if (*fmt == 'X')
// 		len += ft_putnbr2_bo(va_arg(args, unsigned int), 'X');
// 	else
// 		fmt++;
// 	return (len);
// }

int	ft_putnbr_bo(int num, char flag)
{
	int		len;
	long	n;

	len = 0;
	if (num >= 0 && flag == '+')
		len += ft_putchar('+');
	if (num >= 0 && flag == ' ')
		len += ft_putchar(' ');
	n = num;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += ft_putchar((n % 10) + 48);
	return (len);
}

// int	ft_putstr_bo(char *s, int wide)
// {
// 	int	len;
// 	int	i;

// 	len = 0;
// 	i = 0;
// 	if (!s)
// 		return (write(1, "(null)", 6));
// 	len += write(1, " ", wide);
// 	return (len);
// }

int	ft_putnbr2_bo(unsigned int num, char flag)
{
	int	len;

	len = 0;
	if (num == 0)
	{
		len += write(1, "0", 1);
		return (1);
	}
	if (num >= 16)
		len += ft_putnbr2_bo(num / 16, flag);
	if (flag != 'X')
	{
		if (len == 0)
			len += write(1, "0x", 2);
		len += write(1, &"0123456789abcdef"[num % 16], 1);
	}
	else
	{
		if (len == 0)
			len += write(1, "0X", 2);
		len += write(1, &"0123456789ABCDEF"[num % 16], 1);
	}
	return (len);
}