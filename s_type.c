/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:52:43 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 11:17:56 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	if (!s)
	{
		num += write(fd, "(null)", 6);
		return (num);
	}
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		num++;
		i++;
	}
	return (num);
}

int	ft_s_type(va_list ap)
{
	char	*s;
	int		num;

	s = va_arg(ap, char *);
	num = ft_putstr_fd(s, 1);
	return (num);
}
