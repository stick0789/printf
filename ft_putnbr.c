/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 08:44:38 by jaacosta          #+#    #+#             */
/*   Updated: 2024/08/15 08:44:40 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	strnbr[10];
	int		strlength;
	int		i;

	i = 0;
	strlength = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb > 0)
	{
		strnbr[strlength++] = (nb % 10) + '0';
		nb = nb / 10;
	}
	while (--strlength >= 0)
	{
		write(1, &strnbr[strlength], 1);
	}
}
/*
int	main(void)
{
	ft_putnbr(555555542);
	return (0);
}*/
