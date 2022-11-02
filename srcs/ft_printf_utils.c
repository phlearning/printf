/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:04:26 by pvong             #+#    #+#             */
/*   Updated: 2022/11/02 15:41:34 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printnbr(va_list args)
{
	int	nbr;

	nbr = ft_itoa(args)
}