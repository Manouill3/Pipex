/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:30:44 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/20 15:37:09 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char ** av/*, char **envp*/)
{    
    t_data  param;
    int fd[2];
    
    if (ac == 5)
    {
        init_val(&param);
        if (open_fd(&param, av) == -1)
            return (-1);
        fd[0] = param.fd_in;
        fd[1] = param.fd_out;
        exec(&param, fd);
        check_access(av);
    }
}
