/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:38:51 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/27 09:27:38 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    open_file(int ac, char **av, t_data *param)
{
    param->fd.fd_infile = -1;
    param->fd.fd_outfile = -1;
    if (access(av[1], R_OK | F_OK) != -1)
        param->fd.fd_infile = open(av[1], O_RDONLY, 0644);
    else 
        perror("infile");
    if (access(av[ac - 1], F_OK | W_OK) != -1)
        param->fd.fd_outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    else 
    {
        if (access(av[ac - 1], F_OK) == -1)
            param->fd.fd_outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        perror("Outfile");
    }
}

void    init(int ac, char ** av, t_data *param, char **envp)
{
    int count;

    count = 0;
    param->cmd_count = ac - 3;
    open_file(ac, av, param);
    param->fd.pipe_fd[1] = param->fd.fd_infile;
    param->fd.pipe_fd[0] = param->fd.fd_outfile;
    while (count < param->cmd_count)
    {
        if (pipe(param->fd.pipe_fd) == - 1)
            exit(1);
        ft_exec(param, envp, av, count);
        count++; 
    }
}
