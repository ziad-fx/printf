/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:58:45 by zyahansa          #+#    #+#             */
/*   Updated: 2024/11/30 13:22:11 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_my_homie(char format, char homie, int nbr)
{
	if ((format == 'd' || format == 'i') && (homie == '+' && nbr >= 0))
		return (ft_putchar_fd('+', 1), 1);
	if ((format == 'd' || format == 'i') && (homie == ' ' && nbr >= 0))
	{
		ft_putchar_fd(' ', 1);
		return (1);
	}
	if (homie == '#' && nbr != 0)
	{
		if (format == 'x')
		{
			ft_putstr_fd("0x", 1);
			return (2);
		}
		else if (format == 'X')
		{
			ft_putstr_fd("0X", 1);
			return (2);
		}
	}
	return (0);
}

int	ft_printf_spec_num(char format, char homie, va_list ap)
{
	unsigned int	nbr;
	int				counter;

	nbr = 0;
	counter = 0;
	if (format == 'd' || format == 'i')
	{
		nbr = va_arg(ap, int);
		return (counter += check_my_homie(format, homie, nbr)
			+ ft_putnbr_fd(nbr, 1));
	}
	else if (format == 'u')
		return (ft_putnbr_base_fd(va_arg(ap, unsigned int),
				"0123456789", 1));
	else if (format == 'x' || format == 'X')
	{
		nbr = (unsigned int)va_arg(ap, int);
		counter += check_my_homie(format, homie, nbr);
		if (format == 'x')
			return (counter += ft_putnbr_base_fd(nbr, "0123456789abcdef", 1));
		else
			return (counter += ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1));
	}
	return (0);
}

int	ft_printf_spec(char format, char homie, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		return (ft_putchar_fd((char)va_arg(ap, int), 1));
	else if (format == 'd' || format == 'i' || format == 'u')
		return (ft_printf_spec_num(format, homie, ap));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'p')
		return (ft_putstr_fd("0x", 1)
			+ ft_putnbr_base_fd((unsigned long)va_arg(ap, void *),
				"0123456789abcdef", 1));
	else if (format == 'x' || format == 'X')
		return (ft_printf_spec_num(format, homie, ap));
	return (0);
}

int	printf_helper(const char *format, int *index, va_list ap)
{
	char	homie;
	int		counter;

	homie = 0;
	counter = 0;
	(*index)++;
	while (format[*index] == '+' || format[*index] == '#'
		|| format[*index] == ' ')
	{
		homie = format[*index];
		(*index)++;
	}
	counter += ft_printf_spec(format[*index], homie, ap);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	int		index;
	int		counter;
	va_list	ap;

	index = 0;
	counter = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(ap, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '\0')
				break ;
			counter += printf_helper(format, &index, ap);
		}
		else
			counter += ft_putchar_fd(format[index], 1);
		index++;
	}
	va_end(ap);
	return (counter);
}
