/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:21:37 by mdegache          #+#    #+#             */
/*   Updated: 2024/12/18 11:20:44 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort_format(int i, const char *fmt, va_list arg)
{
	int	count;

	count = 0;
	if (fmt[i] == 's')
		count += param_s(arg);
	else if (fmt[i] == 'd')
		count += param_d(arg);
	else if (fmt[i] == 'c')
		count += param_c(arg);
	else if (fmt[i] == 'i')
		count += param_i(arg);
	else if (fmt[i] == 'u')
		count += param_u(arg);
	else if (fmt[i] == 'x')
		count += param_xl(arg);
	else if (fmt[i] == 'X')
		count += param_xu(arg);
	else if (fmt[i] == '%')
		count += ft_putchar('%');
	else if (fmt[i] == 'p')
		count += param_p(arg);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	int		count;
	int		i;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == 0)
			write(1, "-1", 2);
		if (fmt[i] == '%')
		{
			i++;
			count += sort_format(i, fmt, arg);
		}
		else
		{
			ft_putchar(fmt[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
