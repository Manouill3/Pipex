/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:48:11 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/31 14:07:00 by mdegache         ###   ########.fr       */
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
# include "sys/wait.h"

typedef struct s_fd
{
    int fd_infile;
    int fd_outfile;
    int pid;
    int pipe_fd[2];
} t_fd;

typedef struct
{
    int     ac;
    int     cmd_count;
    t_fd    fd;
}   t_data;

void    init(char ** av, t_data *param, char **envp);
void    open_file(int ac, char **av, t_data *param);
char    **make_path(char **envp);
void    ft_exec(t_data *param, char **envp, char **av, int count);
void    child_process(t_data *param, char **envp, char **av, int count);
char    **set_args(char **cmd_path, char **path);
void    free_one_tab(char **tab);
void    parent_process(t_data *param);
void    ft_dup_file(t_data *param, int count);
void    exec_cmd(char **envp, char **av, int count);
void    close_all(t_data *param);
void    verif_fd(int count, t_data *param);

#endif