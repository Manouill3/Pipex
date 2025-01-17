/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:32:40 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/23 16:17:40 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	param_p(va_list arg)
{
	void	*p;
	int		count;

	count = 0;
	p = va_arg(arg, void *);
	if (!p)
		count += ft_putstr("(nil)");
	else
		count += ft_pointer(p);
	return (count);
}

int	param_xl(va_list arg)
{
	unsigned int	xl;
	int				count;

	count = 0;
	xl = va_arg(arg, unsigned int);
	count += ft_putnbr_base(xl, "0123456789abcdef");
	return (count);
}

int	param_xu(va_list arg)
{
	unsigned int	xu;
	int				count;

	count = 0;
	xu = va_arg(arg, unsigned int);
	count += ft_putnbr_base(xu, "0123456789ABCDEF");
	return (count);
}
