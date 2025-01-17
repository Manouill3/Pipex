/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:38:01 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/29 15:26:18 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_printf(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (6);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(long long n, char *base)
{
	int	len;
	int	count;

	count = 0;
	len = ft_strlen_printf(base);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		count++;
	}
	if (n >= len)
		count += ft_putnbr_base(n / len, base);
	ft_putchar(base[n % len]);
	count++;
	return (count);
}
