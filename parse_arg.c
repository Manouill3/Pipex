/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:55:05 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/23 15:07:55 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    **make_path(char **envp)
{
    int i;
    
    i = 0;
    while (envp[i])
    {
        if (ft_strncmp("PATH", envp[i], 4) == 0)
            return (ft_split(envp[i + 5], ':'));
    }
    return (NULL);
}

char    **set_args(char **args, char **path)
{
    int i;

    i = 0;
    while (path[i])
}
