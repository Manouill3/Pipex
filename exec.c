/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:28 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/23 11:44:44 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_exec(t_data *param, char **envp, char **av, int count)
{
    pid_t   pid;
    
    pid = fork();
    if (pid == -1)
        perror("pid");
    if (pid == 0)
    {
        close (param->fd_pipe->fd_infile);
        child_process(param, envp, av, count);
        close (param->fd_pipe->fd_outfile);
    }
    else
    {
        close (param->fd_pipe->fd_outfile);
        //parent_process();
        close (param->fd_pipe->fd_infile);
    }
}

void    child_process(t_data *param, char **envp, char **av, int count)
{
    char    **path;
    char    **args;

    dup2(param->fd_pipe->fd_outfile, STDOUT_FILENO);
    path = make_path(envp);
    args = set_args(ft_split(av[count], ' '), path);
    if (!path || !args)
        ft_free_tab(path, args);
    if (execve(path, args, envp) == -1) // execve(args[0], args, envp);
    {
        perror("execve");
        ft_free_tab(path, args);
        exit (127);
    }
}

