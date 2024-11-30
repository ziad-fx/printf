/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:03:09 by zyahansa          #+#    #+#             */
/*   Updated: 2024/11/27 19:36:23 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	while (s[i])
	{
		len += write(fd, &s[i], 1);
		i++;
	}
	return (len);
}
