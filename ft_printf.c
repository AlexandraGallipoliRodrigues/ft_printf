/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:53:59 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 11:10:35 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int	ft_data_type(const char *format, va_list ap, int *i)
{
	char	*temp;
	int		num;

	temp = ft_strdup(format);
	num = 0;
	if (temp[*i] == 'c')
		num += ft_c_type(ap);
	else if (temp[*i] == 's')
		num += ft_s_type(ap);
	else if (temp[*i] == 'x')
		num += ft_x_type(ap);
	else if (temp[*i] == 'X')
		num += ft_x_upper_type(ap);
	else if (temp[*i] == 'i' || temp[*i] == 'd')
		num += ft_i_d_type(ap);
	else if (temp[*i] == 'u')
		num += ft_u_type(ap);
	else if (temp[*i] == 'p')
		num += ft_p_type(ap);
	else if (temp[*i] == '%')
		num += ft_putchar_fd('%', 1);
	free(temp);
	temp = NULL;
	return (num);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		num;
	va_list	ap;

	num = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			num += ft_data_type(format, ap, &i);
		}
		else
			num += write(1, &format[i], 1);
		i++;
	}
	return (num);
}
