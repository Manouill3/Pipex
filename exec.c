/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:54:28 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/20 15:40:29 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    parent_process()
{
    
}

void    child_process()
{
    
}

void    exec(t_data *param, int fd[2])
{
    pid_t   pid;
    char    buffer[13];

    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(1);
    }
    pid = fork();
    if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	if (pid == 0)
        child_process();
	else
        parent_process();
}
