/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:05:35 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/23 22:05:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_free_tab(char **path, char **args)
{
    if (!path && !args)
        exit(127);
    if (!args)
    {
        free_one_tab(path);
        exit(127);
    }
    if (!path)
    {
        free_one_tab(args);
        exit(127);
    }
    free_one_tab(args);
    free_one_tab(path);
    exit(127);    
}

void    free_one_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free (tab);
}