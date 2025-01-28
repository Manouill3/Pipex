/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 09:05:35 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/28 09:09:34 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void    free_one_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        free(tab[i++]);
    free (tab);
}

void    close_all(t_data *param)
{
    if (param->fd.fd_infile != -1)
        close (param->fd.fd_infile);
    if (param->fd.fd_outfile != -1)
        close (param->fd.fd_outfile);
    if (param->fd.pipe_fd[0] != -1)
        close (param->fd.pipe_fd[0]);
    if (param->fd.pipe_fd[1] != -1)
        close (param->fd.pipe_fd[1]);
}
