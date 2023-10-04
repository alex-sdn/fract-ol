/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:04:15 by asadanow          #+#    #+#             */
/*   Updated: 2022/11/24 17:16:02 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_pf(uintptr_t ptr)
{
	char	*base;

	base = "0123456789abcdef";
	if (ptr < 16)
		return (ft_putchar_pf(base[ptr]));
	else
		return (ft_putptr_pf(ptr / 16) + ft_putptr_pf(ptr % 16));
}

int	ft_print_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr_pf(PTR_NULL));
	len += write(1, "0x", 2);
	len += ft_putptr_pf(ptr);
	return (len);
}
