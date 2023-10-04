/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:38:13 by asadanow          #+#    #+#             */
/*   Updated: 2022/11/24 18:15:14 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(char c, va_list ap, int len)
{
	if (c == 'c')
		len += ft_putchar_pf(va_arg(ap, int));
	else if (c == 's')
		len += ft_putstr_pf(va_arg(ap, char *));
	else if (c == 'p')
		len += ft_print_ptr((uintptr_t)va_arg(ap, void *));
	else if (c == 'd')
		len += ft_putnbr_pf(va_arg(ap, int));
	else if (c == 'i')
		len += ft_putnbr_pf(va_arg(ap, int));
	else if (c == 'u')
		len += ft_putnbr_unsigned_pf(va_arg(ap, unsigned int));
	else if (c == 'x')
		len += ft_putnbr_hex_pf((unsigned int)va_arg(ap, int), 'm');
	else if (c == 'X')
		len += ft_putnbr_hex_pf(va_arg(ap, int), 'M');
	else if (c == '%')
		len += ft_putchar_pf('%');
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len = ft_conversions(s[i + 1], ap, len);
			if (len < 0)
			{
				va_end(ap);
				return (len);
			}
			i++;
		}
		else
			len += ft_putchar_pf(s[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
