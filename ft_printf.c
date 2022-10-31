/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:49:56 by pvong             #+#    #+#             */
/*   Updated: 2022/10/31 19:32:51 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

/* void va_start(va_list ap, last);
       type va_arg(va_list ap, type);
       void va_end(va_list ap);
       void va_copy(va_list dest, va_list src);*/

// I need to detect the argument which are in between quotes: "..."
// I need to detect the characters and print it: write

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
// I need to detect the numbers and print it: putnumbers

// I need at least 3 functions for the flags in the args: 
// one for the field width 
// one for the precision (corresponding to numbers after "." for e)
// Another for the format

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == c)
				ft_putchar();
			else if (*str == s)
				ft_printstr();
			else if (*str == p)
				ft_printptr();
			else if (*str == 
		}
		str++;
	}
	return (0);
}
