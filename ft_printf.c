/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarts <aarts@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:41:25 by aarts             #+#    #+#             */
/*   Updated: 2022/03/09 17:46:23 by aarts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf ( const char * format, ... )
{
	int i;
	int ret;
	va_list(data);
	int length_of_format;
	
	length_of_format = ft_strlen(format);
	va_start(data, format);
	i = 0;
	ret = 0;
	
	while(i<length_of_format)
	{
		if (format[i]=='%')
		{
			i++;
			ret = flagcheck(format, ret, data, i);
		}
		else
			ret = ft_putchar(format[i], ret);
		i++;
	}
	va_end(data);
	return(ret);
}

int	flagcheck (const char * format,int ret ,va_list data, int i)
{
	if (format[i]=='i' || format[i]=='d')
		ret = ft_putnbr(va_arg(data, int), ret);
	else if (format[i]=='c')
		ret = ft_putchar(va_arg(data, int), ret);
	else if (format[i]=='s')
		ret = ft_putstr(va_arg(data, char *), ret);
	else if (format[i]=='%')
		ret = ft_putchar('%', ret);
	else if (format[i]=='u')
		ret = ft_putunbr(va_arg(data, unsigned int), ret);
	else if (format[i]=='x')
		ret = ft_putsmolhex(va_arg(data, long int), ret);
	else if (format[i]=='X')
		ret = ft_putbighex(va_arg(data, long int), ret);
	else if (format[i]=='p')
	{
		ret = ft_putstr("0x", ret);
		ret = ft_putadress((unsigned long long int)va_arg(data, void *), ret);
	}
	return(ret);
}

// int main()
// {
// 	int f = ft_printf("%d ++ %c ++ %s ++ %i ++ %% ++ %u ++ %x ++ %X ++ %p\n", 123456, 'M', "thank you Marie", 654321, 45126, 77, 77, "stringy thingy");
// 	int fsys = printf("%d ++ %c ++ %s ++ %i ++ %% ++ %u ++ %x ++ %X ++ %p\n", 123456, 'M', "thank you Marie", 654321, 45126, 77, 77, "stringy thingy");
// 	// int f = ft_printf("%dddddddd\n", 100000000);
// 	// int fsys = printf("%dddddddd\n", 100000000);
// 	printf("our value = %d", f);
// 	putchar('\n');
// 	printf("real value = %d", fsys);
// 	putchar('\n');
// }
