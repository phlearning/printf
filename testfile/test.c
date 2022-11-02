
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (1);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int len;
	char	*str;

	str = ft_itoa(n);
	len = ft_printstr(str);
	return (len);
}

int ft_printhex(unsigned long n)
{
	unsigned long	tmp;
	int				len;
	
	len = 0;
	if (n > 0)
	{
		ft_printhex(n%16);
		ft_printhex(n/16);
	}
	if (n >= 0 && n < 10)
		len += ft_printnbr(n);
	if (n >= 10 && n <= 16)
	{
		tmp = n + 55;
		//len += ft_printchar(tmp);
	}
	return (len);
}
int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if (str[i] == 'c')
				len += ft_printchar(va_arg(args, int));
			else if (str[i] == 's')
				len += ft_printstr(va_arg(args, char *));
			else if (str[i] == 'd' || str[i] == 'i')
				len += ft_printnbr(va_arg(args, int));
			else if (str[i] == 'x')
				len += ft_printhex(va_arg(args, unsigned long));
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}

int	main(int argc, char **argv)
{
	(void) argc;
	char	c;

	c = 'a';
	ft_printf("c: %c\n", c);
	printf("c: %c\n", c);
	ft_printf("s: %s\n", argv[1]);
	printf("s: %s\n", argv[1]);
	ft_printf("d: %d\n", 10);
	printf("d: %d\n", 10);
	ft_printf("x: %x\n", 20);
	printf("x: %x\n", 20);
	return (0);
}
