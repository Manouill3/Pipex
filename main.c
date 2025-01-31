/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:30:44 by mdegache          #+#    #+#             */
/*   Updated: 2025/01/31 08:54:53 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char ** av, char **envp)
{    
    t_data  param;
    
    if (ac < 5)
    {
        ft_putstr_fd("Wrong format, try again\n", 2);
        exit(1);
    }
    param.ac = ac;
    init(av, &param, envp);
}
