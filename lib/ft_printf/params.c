/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:24:53 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/23 16:07:27 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	param_c(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	ft_putchar(c);
	return (1);
}

int	param_s(va_list arg)
{
	int		count;
	char	*s;

	count = 0;
	s = va_arg(arg, char *);
	if (!s)
		ft_putstr("(null)");
	count += ft_putstr(s);
	return (count);
}

int	param_d(va_list arg)
{
	int	d;
	int	count;

	count = 0;
	d = va_arg(arg, int);
	count += ft_putnbr_base(d, "0123456789");
	return (count);
}

int	param_i(va_list arg)
{
	int	i;
	int	count;

	count = 0;
	i = va_arg(arg, int);
	count += ft_putnbr_base(i, "0123456789");
	return (count);
}

int	param_u(va_list arg)
{
	unsigned int	u;
	int				count;

	count = 0;
	u = va_arg(arg, unsigned int);
	count += ft_putnbr_base(u, "0123456789");
	return (count);
}
