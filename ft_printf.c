/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:47 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 20:05:08 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_printf_process(va_list args, char fs)
{
	int	size;

	size = 0;
	if (fs == 'c')
		size += ctrl_putchar(va_arg(args, int));
	else if (fs == 's')
		size += ctrl_putstr(va_arg(args, char *));
	else if (fs == 'p')
		size += ctrl_ptr(va_arg(args, void *));
	else if (fs == 'd' || fs == 'i')
		size += ctrl_putstr(ft_itoa((int)va_arg(args, long), 10));
	else if (fs == 'u')
		size += ctrl_uint(va_arg(args, unsigned int));
	else if (fs == 'x')
		size += ctrl_putstr(ft_itoa(va_arg(args, long long), 16));
	else if (fs == 'X')
		size += ctrl_putstr(ft_toupper(ft_itoa(va_arg(args, long long), 16)));
	else if (fs == '%')
		size += ctrl_putchar('%');
	return (size);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			size += ft_printf_process(args, format[i + 1]);
			i++;
		}
		else
			size += ctrl_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (size);
}
