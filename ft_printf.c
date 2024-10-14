/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:28:47 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/14 21:54:14 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static char	*symbol_printf()
{

}

static int	check_specifier(char c)
{
	if (c == '%')
		i = ft_putchar(va_args(args, int))
	return (c);
}

static int	ft_printf_strprocess(char *format)
{
	char	fs;
	int		i;

	fs = '%';
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == fs)
		{
			
		}
		i++;
	}
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int	res;
	
	va_start(args, format);

	return (res);
}
