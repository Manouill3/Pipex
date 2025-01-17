/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:12:59 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/14 08:32:36 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	unsigned const char	*dtr;
	int					i;

	i = 0;
	dtr = src;
	ptr = dest;
	if (!dest && !src)
		return (0);
	while (n)
	{
		ptr[i] = dtr[i];
		i++;
		n--;
	}
	return (dest);
}
