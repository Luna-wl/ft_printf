/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <Warintorn_L@outlook.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:01:11 by wluedara          #+#    #+#             */
/*   Updated: 2022/10/07 18:33:25 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	check_flag_bonus(const char *fmt, va_list args)
{
	int len;
	int	wide;

	len = 0;
	wide = 0;
	if (*fmt == '#')
	{
		fmt++;
		len += check_bo(fmt, args);
	}
	else if (*fmt == ' ')
	{
		fmt++;
		// printf("fmt = %s\n", fmt);
		len += check_bo(fmt, args);
	}
	else if (*fmt == '+')
	{
		fmt++;
		len += ft_putnbr_bo(va_arg(args, int), '+');
	}
	return (len);
}

int	check_flag(const char *fmt, va_list args)
{
	int	len;

	len = 0;
	if (*fmt == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*fmt == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*fmt == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_puthex(va_arg(args, size_t));
	}
	else if (*fmt == 'd' || *fmt == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (*fmt == 'u')
		len += ft_putnbr2(va_arg(args, unsigned int), 10, 'u');
	else if (*fmt == 'x')
		len += ft_putnbr2(va_arg(args, unsigned int), 16, 'x');
	else if (*fmt == 'X')
		len += ft_putnbr2(va_arg(args, unsigned int), 16, 'X');
	else if (*fmt == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == '#' || *fmt == ' ' || *fmt == '+')
			{
				len += check_flag_bonus(fmt, args);
				fmt++;
			}
			else
				len += check_flag(fmt, args);
		}
		else
			len += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (len);
}

int	main()
{
	printf("\n|%d|\n", ft_printf("% 1s", ""));
}