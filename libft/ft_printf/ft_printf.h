/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:45:10 by asadanow          #+#    #+#             */
/*   Updated: 2022/11/24 17:28:38 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

# if defined (__APPLE__)
#  define PTR_NULL "0x0"
# elif __linux__
#  define PTR_NULL "(nil)"
# endif

int	ft_printf(const char *s, ...);
int	ft_conversions(char c, va_list ap, int len);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_putnbr_pf(int n);
int	ft_putnbr_unsigned_pf(unsigned int n);
int	ft_putnbr_hex_pf(unsigned int n, char c);
int	ft_putptr_pf(uintptr_t ptr);
int	ft_print_ptr(uintptr_t ptr);

#endif
