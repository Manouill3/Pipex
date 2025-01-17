/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:48:45 by mdegache          #+#    #+#             */
/*   Updated: 2024/11/05 09:54:35 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	size_t	i;
	size_t	j;

	if (!s2)
		return (0);
	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
	{
		free (s1);
		return (NULL);
	}
	j = 0;
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		while (s1 && s1[j])
			tab[i++] = s1[j++];
		j = 0;
		while (s2 && s2[j])
			tab[i++] = s2[j++];
	}
	tab[i] = '\0';
	free(s1);
	return (tab);
}
