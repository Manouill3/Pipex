/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 07:25:24 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/14 08:35:46 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*j;

	i = 0;
	j = (unsigned char *)s;
	while (n > 0)
	{
		j[i] = c;
		n--;
		i++;
	}
	return (s);
}
