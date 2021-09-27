/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 13:03:19 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 11:50:08 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_error(char *base)
{
	int	d;
	int	e;
	int	f;

	e = 0;
	d = ft_strlen(base);
	f = 0;
	if (d <= 1)
		return (1);
	while (base[e] != '\0' && base[f] != '\0')
	{
		while (base[e] != '\0' && base[f] != '\0')
		{
			if ((base[e] == base[f] && e != f) || (base[f] == '+'\
						|| base[f] == '-'))
				return (1);
			f++;
		}
		e++;
		f = 0;
	}
	return (0);
}

void	ft_putnbr_base(unsigned int nbr, char *base, int *num)
{
	unsigned int	base_len;

	if (find_error(base) == 0)
	{
		base_len = ft_strlen(base);
		if (nbr < 0)
		{
			*num += write(1, "-", 1);
			ft_putnbr_base(-nbr, base, num);
		}
		else if (nbr >= base_len)
			ft_putnbr_base(nbr / base_len, base, num);
		*num += ft_putchar_fd(base[nbr % base_len], 1);
	}
}

int	ft_x_type(va_list ap)
{
	unsigned int	x;
	int				num;

	num = 0;
	x = va_arg(ap, unsigned int);
	ft_putnbr_base(x, "0123456789abcdef", &num);
	return (num);
}

int	ft_x_upper_type(va_list ap)
{
	unsigned int	x;
	int				num;

	num = 0;
	x = va_arg(ap, unsigned int);
	ft_putnbr_base(x, "0123456789ABCDEF", &num);
	return (num);
}
