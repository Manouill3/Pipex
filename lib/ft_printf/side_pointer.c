/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:42:10 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/23 16:12:38 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(void *p)
{
	unsigned long long	adress;
	int					count;

	count = 0;
	adress = (unsigned long long)p;
	count += ft_putstr("0x");
	count += ft_putpoint(adress, "0123456789abcdef");
	return (count);
}

int	ft_putpoint(unsigned long long n, char *base)
{
	unsigned long long	len;
	int					count;

	len = ft_strlen_printf(base);
	count = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= len)
		count += ft_putpoint(n / len, base);
	ft_putchar(base[n % len]);
	count++;
	return (count);
}
