/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:56:58 by asadanow          #+#    #+#             */
/*   Updated: 2022/11/24 17:14:20 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_pf(unsigned int n, char c)
{
	char			*base;

	if (c == 'm')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
		return (ft_putchar_pf(base[n]));
	else
		return (ft_putnbr_hex_pf(n / 16, c)
			+ ft_putnbr_hex_pf(n % 16, c));
}
