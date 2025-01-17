/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:10:16 by mdegache          #+#    #+#             */
/*   Updated: 2024/12/05 21:40:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	k;
	char	*tab;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	k = 0;
	while (k < len && s[start])
	{
		tab[k] = s[start];
		start++;
		k++;
	}
	tab[k] = '\0';
	return (tab);
}
