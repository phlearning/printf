/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:49:56 by pvong             #+#    #+#             */
/*   Updated: 2022/11/02 15:46:46 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

t_print *ft_init_flags(t_print *tab)
{
	tab->width = 0;
	tab->precision = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->total_length = 0;
	tab->sign = 0;
	tab->zero = 0;
	tab->percent = 0;
	tab->space= 0;
}

/* void va_start(va_list ap, last);
       type va_arg(va_list ap, type);
       void va_end(va_list ap);
       void va_copy(va_list dest, va_list src);*/


int	ft_format_flags(char *format, va_list args, int i)
{
	while (format[i])
	{
		if (format[i] == '.')
			tab->pnt = 1;
		if (format[i] == '-')
			tab->dash = 1;
		if (format[i] == '')
	}
}

// typedef struct s_flags
// {
// 	va_list	args;
// 	int		width;
// 	int		precision;
// 	int		zero;
// 	int		pnt;
// 	int		dash;
// 	int		total_length;
// 	int		sign;
// 	int		zero;
// 	int		percent;
// 	int		space;
// }	t_print;

int	ft_format(char *format, va_list args, int i)
{
	while (format[i])
	{
		if (format[i] == 'c')
			ft_putchar(va_arg(args, int));
		else if (format[i] == 's')
			ft_printstr(va_arg(args, char *));
		else if (format[i] == 'p')
			ft_printptr(va_arg(args, unsigned long));
		else if (format[i] == 'd' || format == 'i')
			ft_printnbr(va_arg(args, int));
		else if (format[i] == 'u')
			ft_printnbr(va_arg(args, unsigned long));
		else if (format[i] == 'x')
			ft_printhex(va_arg(args, unsigned int));
		else if (format[i] == 'X')
			ft_printhex(va_arg(args, unsigned int));
		else if (format[i] == '%')
			ft_printpercent(va_arg(args, int));
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		print;

	
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
	ft_init_flags(tab);
	va_start(tab->args, format);
	i = 0;
	print = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1])
			{
				print = ft_format(format[i+1], tab->args, i);
			}
		}
		else
		{
			print += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(tab->args);
	print += tab->total_length;
	free(tab);
	return (print);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf(argv[1], argv[2]);
	ft_printf(argv[1], argv[2]);
	return (0);
}
