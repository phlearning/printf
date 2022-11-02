/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 10:46:24 by pvong             #+#    #+#             */
/*   Updated: 2022/11/02 16:10:41 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

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

int	ft_printf(const char *format, ...);

#endif