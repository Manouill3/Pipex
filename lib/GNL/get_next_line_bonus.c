/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:07:20 by mdegache          #+#    #+#             */
/*   Updated: 2024/11/06 11:35:29 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*set_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*set_after_line(char *stash)
{
	int		i;
	int		j;
	int		len;
	char	*tmp_stash;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	i++;
	len = ft_strlen(stash) - i;
	if (ft_strchr(stash, '\n'))
	{
		tmp_stash = malloc(sizeof(char) * len + 1);
		if (!tmp_stash)
			return (NULL);
		while (stash[i])
			tmp_stash[j++] = stash[i++];
		tmp_stash[j] = '\0';
	}
	else
		tmp_stash = NULL;
	free (stash);
	return (tmp_stash);
}

char	*read_line(char *stash, int fd)
{
	int		bytes;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	stash[fd] = read_line(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = set_line(stash[fd]);
	if (!line)
	{
		free (line);
		free (stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = set_after_line(stash[fd]);
	if (ft_strlen(line) > 0)
		return (line);
	free(line);
	return (NULL);
}
