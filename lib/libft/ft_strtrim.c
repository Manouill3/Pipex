/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:03:37 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/15 11:08:36 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	c_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_len;
	char	*tab;

	if (!s1 || !set)
		return (0);
	while (c_in_set(*s1, set))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len > 0 && c_in_set(s1[s1_len - 1], set))
		s1_len--;
	tab = ft_calloc(s1_len + 1, sizeof(char));
	if (!tab)
		return (0);
	ft_memcpy(tab, s1, s1_len);
	return (tab);
}
