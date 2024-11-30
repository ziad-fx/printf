/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:13:38 by zyahansa          #+#    #+#             */
/*   Updated: 2024/11/28 17:35:34 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		len += ft_putstr_fd("-2147483648", 1);
	else if (n < 0)
	{
		len += ft_putchar_fd('-', 1);
		n = -n;
		len += ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			len += ft_putnbr_fd(n / 10, fd);
			len += ft_putnbr_fd(n % 10, fd);
		}
		else
		{
			n += '0';
			len += ft_putchar_fd(n, 1);
		}
	}
	return (len);
}

int	ft_putnbr_base_fd(unsigned long nbr, char *base, int fd)
{
	unsigned int	len_base;
	int				len;

	len_base = 0;
	len = 0;
	while (base[len_base])
	{
		len_base++;
	}
	if (nbr >= len_base)
	{
		len += ft_putnbr_base_fd(nbr / len_base, base, fd);
	}
	len += ft_putchar_fd(base[nbr % len_base], fd);
	return (len);
}
