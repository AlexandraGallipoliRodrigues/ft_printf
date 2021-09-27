/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:42:20 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 11:11:46 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	num;

	num = 0;
	num = write(fd, &c, 1);
	return (num);
}

int	ft_c_type(va_list ap)
{
	int	c;
	int	num;

	c = va_arg(ap, int);
	num = ft_putchar_fd(c, 1);
	return (num);
}
