/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:43:03 by mdegache          #+#    #+#             */
/*   Updated: 2024/12/05 21:34:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*t;

	i = 0;
	t = s;
	while (i < n)
	{
		if (t[i] == (unsigned char)c)
			return ((char *) &t[i]);
		i++;
	}
	return (0);
}
