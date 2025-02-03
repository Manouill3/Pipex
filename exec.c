/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:28 by mdegache          #+#    #+#             */
/*   Updated: 2025/02/03 15:29:06 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_exec(t_data *param, char **envp, char **av, int count)
{
    param->fd.pid = fork();
    if (param->fd.pid == -1)
    {
        perror("pid");
        exit (127);
    }
    if (param->fd.pid == 0)
        child_process(param, envp, av, count);
    else
        parent_process(param);
}

void    ft_dup_file(t_data *param, int count)
{
    if (param->cmd_count - 1 == count)
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

void    child_process(t_data *param, char **envp, char **av, int count)
{
    verif_fd(count, param);
    if (count == 0)
    {
        dup2(param->fd.fd_infile, STDIN_FILENO);
        if (param->fd.fd_infile != -1)
            close(param->fd.fd_infile);    
    }
    ft_dup_file(param, count);
    close_all(param);
    exec_cmd(envp, av, count);
}

void    parent_process(t_data *param)
{
    close(param->fd.pipe_fd[1]);
    dup2(param->fd.pipe_fd[0], STDIN_FILENO);
    close (param->fd.pipe_fd[0]);    
}

void    exec_cmd(char **envp, char **av, int count)
{
    char    **path;
    char    **args;
    
    path = make_path(envp);
    if (!path)
        return ;
    args = set_args(ft_split(av[count + 2], ' '), path);
    if (!args || !args[0])
    {
        if (args)
            free_one_tab(args);
        free_one_tab(path);
        exit(127);
    }
    if (execve(args[0], args, envp) == -1)
        {
            perror("execve");
        free_one_tab(path);
        free_one_tab(args);
        exit (127);
    }
}
