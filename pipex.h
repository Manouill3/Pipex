/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:48:11 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/21 14:23:03 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/GNL/get_next_line.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"
# include "errno.h"
# include "unistd.h"
# include "stdio.h"
# include "string.h"
# include "fcntl.h"

typedef struct s_fd
{
    int fd_infile;
    int fd_outfile;
} t_fd;

typedef struct s_data
{
    int     cmd_count;
    t_fd    *fd_pipe;
}   t_data;

void    init(int ac, char ** av, t_data *param);
void    open_file(int ac, char **av, t_data *param);

#endif