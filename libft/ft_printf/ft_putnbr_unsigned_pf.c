/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:52:45 by asadanow          #+#    #+#             */
/*   Updated: 2022/11/24 17:10:45 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned_pf(unsigned int n)
{
	if (n < 10)
		return (ft_putchar_pf(n + 48));
	else
		return (ft_putnbr_unsigned_pf(n / 10) + ft_putnbr_unsigned_pf(n % 10));
}
