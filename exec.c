/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:28 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/22 23:36:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_exec(t_data *param, char **envp)
{
    pid_t   pid;
    
    pid = fork();
    if (pid == -1)
        perror("pid");
    if (pid == 0)
    {
        close (param->fd_pipe->fd_infile);
        child_process(param, envp);
        close (param->fd_pipe->fd_outfile);
    }
    else
    {
        close (param->fd_pipe->fd_outfile);
        parent_process();
        close (param->fd_pipe->fd_infile);
    }
}

void    child_process(t_data *param, char **envp)
{
    char    *path;
    char    **args;

    path = make_path(param, envp);
    
}

void    parent_process()
{
    
}
