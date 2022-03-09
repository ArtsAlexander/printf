/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_moreutils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:02:47 by aarts             #+#    #+#             */
/*   Updated: 2022/03/09 17:14:05 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsmolhex(long int n, int ret)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ret = ft_putchar('-', ret);
		num *= -1;
	}
	if (num < 10)
		ret = ft_putchar(num + '0', ret);
	else if (num <= 16)
		ret = ft_putchar(num + 'a' - 10, ret);
	else
	{
		ret = ft_putsmolhex(num / 16, ret);
		ret = ft_putsmolhex(num % 16, ret);
	}
	return(ret);
}

int	ft_putbighex(long int n, int ret)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ret = ft_putchar('-', ret);
		num *= -1;
	}
	if (num < 10)
		ret = ft_putchar(num + '0', ret);
	else if (num <= 16)
		ret = ft_putchar(num + 'A' - 10, ret);
	else
	{
		ret = ft_putbighex(num / 16, ret);
		ret = ft_putbighex(num % 16, ret);
	}
	return(ret);
}

int	ft_putadress(unsigned long long int n, int ret)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		ret = ft_putchar('-', ret);
		num *= -1;
	}
	if (num < 10)
		ret = ft_putchar(num + '0', ret);
	else if (num <= 16)
		ret = ft_putchar(num + 'a' - 10, ret);
	else
	{
		ret = ft_putadress(num / 16, ret);
		ret = ft_putadress(num % 16, ret);
	}
	return(ret);
}
