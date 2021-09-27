/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallipo <agallipo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:14:23 by agallipo          #+#    #+#             */
/*   Updated: 2021/09/23 11:51:53 by agallipo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_data_type(const char *format, va_list args, int	*i);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_base(unsigned int nbr, char *base, int *num);
int		find_error(char *base);
void	ft_putnbr_base_p(unsigned long int nbr, char *base, int *num);
void	ft_putnbr_fd(int nbr, int fd, int *num);
void	ft_putnbr(unsigned int n, int fd, int *num);
int		ft_c_type(va_list ap);
int		ft_s_type(va_list ap);
int		ft_x_type(va_list ap);
int		ft_x_upper_type(va_list ap);
int		ft_i_d_type(va_list ap);
int		ft_u_type(va_list ap);
int		ft_p_type(va_list ap);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
#endif
