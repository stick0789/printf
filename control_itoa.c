/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:24:15 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 20:21:16 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_len(long long n, int base)
{
	int	len;

	len = 1;
	if (n < 0 && base == 10)
	{
		n *= -1;
		len++;
	}
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}

static void	ft_putn_save(long long n, char *s, int *i, int base)
{
	char	*hexdigit;

	hexdigit = "0123456789abcdef";
	if (n >= base)
	{
		ft_putn_save(n / base, s, i, base);
		ft_putn_save(n % base, s, i, base);
	}
	else
		s[(*i)++] = hexdigit[n];
}

char	*ft_itoa(long long n, int base)
{
	char	*s;
	int		i;
	int		len;

	len = ft_len(n, base);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	i = 0;
	if (n < 0 && base == 10)
	{
		s[i++] = '-';
		n *= -1;
	}
	ft_putn_save(n, s, &i, base);
	s[i] = '\0';
	return (s);
}
