/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaacosta <jaacosta@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:43:01 by jaacosta          #+#    #+#             */
/*   Updated: 2024/10/22 20:34:28 by jaacosta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
char			*ft_toupper(char *s);
int				ctrl_putchar(char c);
int				ctrl_putstr(char *s);
char			*ft_itoa(long long n, int base);
int				ctrl_ptr(va_list args);
unsigned int	ctrl_uint(unsigned int n);

#endif
