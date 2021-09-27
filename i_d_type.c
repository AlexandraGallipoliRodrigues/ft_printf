/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_d_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:34:55 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 10:42:31 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int nbr, int fd, int *num)
{
	if (nbr == -2147483648)
		*num = write(fd, "-2147483648", 11);
	if (nbr != -2147483648)
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			*num += 1;
			nbr = -nbr;
		}
		if (nbr >= 10)
		{
			*num += 1;
			ft_putnbr_fd(nbr / 10, fd, num);
			ft_putchar_fd(nbr % 10 + '0', fd);
		}
		else
		{
			ft_putchar_fd(nbr + '0', fd);
			*num += 1;
		}
	}
}

int	ft_i_d_type(va_list ap)
{
	int	d;
	int	num;

	num = 0;
	d = va_arg(ap, int);
	ft_putnbr_fd(d, 1, &num);
	return (num);
}
