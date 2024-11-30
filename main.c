/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:36:34 by zyahansa          #+#    #+#             */
/*   Updated: 2024/11/30 13:58:07 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <libc.h>
#include <fcntl.h>

int	main(void)
{
    close (1);
    int a = ft_printf("hello\n");
    fprintf(stderr, "%d\n", a);
}
