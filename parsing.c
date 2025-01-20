/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:59:54 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/20 15:32:59 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void init_val(t_data *param)
{
    param->valid_infile = 0;
    param->here_doc = 0;
}

int    check_access(char **av)
{
    if (access(av[1], R_OK) == -1)
        return(-1);
    if (access(av[4], W_OK) == -1 || access(av[4], R_OK) == -1)
        return(-1);
    return(0);
}

int open_fd(t_data *param, char **av)
{
    param->fd_in = open(av[1], O_RDONLY);
    param->fd_out = open(av[4], O_WRONLY | O_CREAT);
    if (param->fd_in < 0 || param->fd_out < 0)
        return(-1);
    return(0);
}