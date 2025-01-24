/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:55:05 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/24 09:02:28 by mdegache         ###   ########.fr       */
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
    char *tmp;

    i = 0;
    while (path[i])
    {
        tmp = ft_strjoin(path[i], args[0]);
        if (access(tmp, R_OK | F_OK) != -1)
        {
            free(args[0]);
            args[0] = tmp;
            return (args);
        }
        i++;
    }
    return (args);
}
