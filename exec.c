/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:28 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/24 13:22:51 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    ft_exec(t_data *param, char **envp, char **av, int ac, int count)
{
    pid_t   pid;
    
    pid = fork();
    if (pid == -1)
        perror("pid");
    if (pid == 0)
        child_process(param, envp, av, ac, count);
    else
        parent_process(param);
}

void    child_process(t_data *param, char **envp, char **av, int ac, int count)
{
    char    **path;
    char    **args;

    if (count == 2)
    {
        dup2(param->fd_pipe.fd_infile, STDIN_FILENO);
        close (param->fd_pipe.fd_outfile);
    }
    if (count == ac - 2)
    {
        dup2(param->fd_pipe.fd_outfile, STDOUT_FILENO);
        close (param->fd_pipe.fd_outfile); 
    }
    path = make_path(envp);
    args = set_args(ft_split(av[count], ' '), path);
    ft_printf("HERE\n");
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
    dup2(param->fd_pipe.fd_infile, STDIN_FILENO);
    close (param->fd_pipe.fd_infile);    
}

