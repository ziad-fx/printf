/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:58:49 by zyahansa          #+#    #+#             */
/*   Updated: 2024/11/30 11:24:33 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_base_fd(unsigned long nbr, char *base, int fd);

#endif