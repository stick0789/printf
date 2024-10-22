/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_voidptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:15:21 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 18:21:40 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ctrl_ptr(va_list args)
{
	int		size;
	void	*ptr;

	ptr = args;
	size = 0;
	if (ptr == NULL)
		size += ctrl_putstr("(nil)");
	else
	{
		size += ctrl_putstr("0x");
		size += ctrl_putstr(ft_itoa((unsigned long)ptr, 16));
	}
	return (size);
}
