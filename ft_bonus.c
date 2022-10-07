/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:07:28 by wluedara          #+#    #+#             */
/*   Updated: 2022/10/07 18:33:29 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_bo(const char *fmt, va_list args)
{
	int	len;

	len = 0;
	if (*fmt == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*fmt == 'd' || *fmt == 'i')
		len += ft_putnbr_bo(va_arg(args, int), ' ');
	else if (*fmt == 'x')
	{
		len += write(1, "0x", 2);
		len += ft_putnbr2_bo(va_arg(args, unsigned int), 'x');
	}
	else if (*fmt == 'X')
	{
		len += write(1, "0X", 2);
		len += ft_putnbr2_bo(va_arg(args, unsigned int), 'X');
	}
	return (len);
}

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

int	ft_putstr_bo(char *s, int wide)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	else
		len += write(1, " ", wide);
	while (s[i] != '\0')
	{
		len += ft_putchar(s[i]);
		i++;
	}
	return (len);
}

int	ft_putnbr2_bo(unsigned int num, char flag)
{
	int	len;

	len = 0;
	if (num >= 16)
		len += ft_putnbr2_bo(num / 16, flag);
	if (flag != 'X')
		len += write(1, &"0123456789abcdef"[num % 16], 1);
	else
		len += write(1, &"0123456789ABCDEF"[num % 16], 1);
	return (len);
}