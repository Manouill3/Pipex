/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:28 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/27 10:51:41 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_exec(t_data *param, char **envp, char **av, int count)
{
    param->fd.pid = fork();
    if (param->fd.pid == -1)
        perror("pid");
    if (param->fd.pid == 0)
        child_process(param, envp, av, count);
    else
        parent_process(param);
}

void    child_process(t_data *param, char **envp, char **av,int count)
{
    char    **path;
    char    **args;

    if (count == 0)
    {
        dup2(param->fd.fd_infile, STDIN_FILENO);
        if (param->fd.fd_infile != -1)
            close(param->fd.fd_infile);
    }
    ft_dup_file(param, count);
    path = make_path(envp);
    args = set_args(ft_split(av[count + 2], ' '), path);
    if (!path || !args)
        ft_free_tab(path, args);
    if (execve(args[0], args, envp) == -1)
    {
        perror("execve");
        ft_free_tab(path, args);
        exit (127);
    }
}

void    parent_process(t_data *param)
{
    waitpid(param->fd.pid, NULL, 0);
    //dup2(param->fd.fd_outfile, STDOUT_FILENO);
    //close (param->fd.fd_outfile);    
}

void    ft_dup_file(t_data *param, int count)
{
    if (param->cmd_count - 2 == count)
    {
        if (param->fd.pipe_fd[0] != -1)
            close(param->fd.pipe_fd[0]);
        if (param->fd.pipe_fd[1] != -1)
            close(param->fd.pipe_fd[1]);
        dup2(param->fd.fd_outfile, STDOUT_FILENO);
    }
    else
    {
        if (param->fd.pipe_fd[0] != -1)
            close(param->fd.pipe_fd[0]);
        dup2(param->fd.pipe_fd[1], STDOUT_FILENO);
        if (param->fd.pipe_fd[1] != -1)
            close(param->fd.pipe_fd[1]);
    }
}
