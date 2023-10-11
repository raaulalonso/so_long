/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalonso <raalonso@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:52:37 by raalonso          #+#    #+#             */
/*   Updated: 2023/07/15 19:51:44 by raalonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(char const *print, ...);
int	ft_puthex(unsigned int n, int flag);
int	ft_putmem(void *mem);
int	ft_puthexmem(uintptr_t n, int flag);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putstr_fd(char *s, int fd);

#endif