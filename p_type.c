/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:52:37 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 11:50:32 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_p(unsigned long int nbr, char *base, int *num)
{
	unsigned long int	i;
	unsigned long int	c;

	if (find_error(base) == 0)
	{
		i = ft_strlen(base);
		if (nbr < 0)
		{
			*num += write(1, "-", 1);
			ft_putnbr_base_p(-nbr, base, num);
		}
		if (nbr > 0)
		{
			 ft_putnbr_base_p(nbr / i, base, num);
			 c = nbr % i;
			 *num += write(1, &base[c], 1);
		}
	}
}

int	ft_p_type(va_list ap)
{
	unsigned long int	p;
	int					num;

	num = 0;
	p = va_arg(ap, unsigned long int);
	num += write(1, "0x", 2);
	if (p == 0)
		num += write(1, "0", 1);
	ft_putnbr_base_p((unsigned long int)p, "0123456789abcdef", &num);
	return (num);
}
