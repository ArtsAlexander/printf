/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:54:03 by aarts             #+#    #+#             */
/*   Updated: 2022/03/09 17:51:24 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_putchar(char c, int ret);
int		ft_putstr(char *s, int ret);
int		ft_putnbr(int n, int ret);
int		ft_putunbr(unsigned int n, int ret);
int		ft_putsmolhex(long int n, int ret);
int		ft_putbighex(long int n, int ret);
int		ft_putadress(unsigned long long int n, int ret);
int		flagcheck (const char * format,int ret ,va_list data, int i);


#endif