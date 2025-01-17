/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 07:36:05 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/14 08:55:19 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n - 1 && s1[i] && s1[i] == s2[i])
		i++;
	if (n == 0)
		return (0);
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
