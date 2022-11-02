/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:49:56 by pvong             #+#    #+#             */
/*   Updated: 2022/11/02 12:04:16 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

typedef struct s_flags
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		pnt;
	int		dash;
	int		total_length;
	int		sign;
	int		zero;
	int		percent;
	int		space;
}	t_print;

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

// I need to detect the argument which are in between quotes: "..."
// I need to detect the characters and print it: write

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
// I need to detect the numbers and print it: putnumbers & itoa


// I need at least 3 functions for the flags in the args:

// one for the field width
// one for the precision (corresponding to numbers after "." for e)
// Another for the format




int	ft_format(char format, va_list args)
{
	if (format == 'c')
		ft_putchar(va_arg(args, int));
	else if (format == 's')
		ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		ft_printmbr(va_arg(args, unsigned long));
	else if (format == 'd')
		ft_printnbr(va_arg(args, int);
	else if (format == 'i')
		ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		ft_printunbr(va_arg(args, unsigned long));
	else if (format == 'x')
		ft_printhex(va_arg(args, unsigned int));
	else if (format == 'X')
		ft_printhex(va_arg(args, unsigned int));
	else if (format == '%')
		ft_printpercent(va_arg(args, int));
}

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		print;

	i = 0;
	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i+1])
				i++;
			print = ft_format(str, args);
		}
		i++;
	}
	va_end(args);
	return (print);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf("%s\n", argv[1]);
	ft_printf("%s\n", argv[1]);
	return (0);
}
