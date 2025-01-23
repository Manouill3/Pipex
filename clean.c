/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:05:35 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/23 09:21:37 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_free_tab(char *path, char **args)
{
    int i;

    i = 0;
    if (!path && !args)
        exit(127);
    if (!args)
    {
        free(path);
        exit(127);
    }
    if (!path)
    {
        while (args[i])
            free(args[i++]);
        free (args);
        exit(127);
    }
    while (args[i])
        free(args[i++]);
    free (args);
    free(path);
    exit(127);    
}
