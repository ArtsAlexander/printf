/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:56:07 by aarts             #+#    #+#             */
/*   Updated: 2022/03/09 17:13:33 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

int	ft_putchar(char c, int ret)
{
	write(1, &c, 1);
	ret += 1;
	return(ret);
}

int	ft_putstr(char *s, int ret)
{
	while(*s)
	{
		ret = ft_putchar(*s, ret);
		s++;
	}
	return(ret);
}

int	ft_putnbr(int n, int ret)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ret = ft_putchar('-', ret);
		num *= -1;
	}
	if (num <= 9)
		ret = ft_putchar(num + '0', ret);
	else
	{
		ret = ft_putnbr(num / 10, ret);
		ret = ft_putnbr(num % 10, ret);
	}
	return(ret);
}

int	ft_putunbr(unsigned int n, int ret)
{
	long int	num;

	num = n;
	if (num <= 9)
		ret = ft_putchar(num + '0', ret);
	else
	{
		ret = ft_putunbr(num / 10, ret);
		ret = ft_putunbr(num % 10, ret);
	}
	return(ret);
}
