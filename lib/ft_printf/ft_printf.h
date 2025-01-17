/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdegache <mdegache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:03:48 by mdegache          #+#    #+#             */
/*   Updated: 2024/10/24 09:25:39 by mdegache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "unistd.h"
# include "stdarg.h"

int	sort_format(int i, const char *fmt, va_list arg);
int	ft_printf(const char *fmt, ...);
int	param_c(va_list arg);
int	param_s(va_list arg);
int	param_d(va_list arg);
int	param_i(va_list arg);
int	param_u(va_list arg);
int	param_xl(va_list arg);
int	param_xu(va_list arg);
int	param_p(va_list arg);
int	ft_strlen_printf(const char *str);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr_base(long long n, char *base);
int	ft_pointer(void *p);
int	ft_putpoint(unsigned long long n, char *base);

#endif
