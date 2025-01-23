/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:20:48 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/23 14:34:32 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!tab)
		return (NULL);
	j = 0;
	while (s1[j])
		tab[i++] = s1[j++];
	tab[i++] = '/';
	j = 0;
	while (s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	return (tab);
}
