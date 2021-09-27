/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:45:26 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 11:19:36 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned int n, int fd, int *num)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, fd, num);
		ft_putchar_fd(nbr % 10 + '0', fd);
		*num += 1;
	}
	else
	{
		ft_putchar_fd(nbr + '0', fd);
		*num += 1;
	}
}

int	ft_u_type(va_list ap)
{
	unsigned int	u;
	int				num;

	num = 0;
	u = va_arg(ap, unsigned int);
	ft_putnbr(u, 1, &num);
	return (num);
}
