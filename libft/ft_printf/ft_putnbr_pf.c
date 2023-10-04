/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:39:10 by asadanow          #+#    #+#             */
/*   Updated: 2022/11/24 17:15:02 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	unsigned int	new;
	int				neg;

	neg = 0;
	if (n < 0)
	{
		neg = ft_putchar_pf('-');
		new = -n;
	}
	else
		new = n;
	if (new < 10)
		return (neg + ft_putchar_pf(new + 48));
	else
		return (neg + ft_putnbr_pf(new / 10) + ft_putnbr_pf(new % 10));
}
