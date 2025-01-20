/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:48:11 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/20 15:37:56 by mdegache         ###   ########.fr       */
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

typedef struct s_data
{
    int     fd_in;
    int     fd_out;
    int     valid_infile;
    int     here_doc;
    int     cmd_count;
    char    **cmd_paths;
    char    ***cmd_args;
}   t_data;

void    exec(t_data *param, int fd[2]);
int open_fd(t_data *param, char **av);
void init_val(t_data *param);
int    check_access(char **av);


#endif