/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:32:25 by asadanow          #+#    #+#             */
/*   Updated: 2023/02/04 16:32:26 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	error_exit(void *ptr)
{
	if (ptr)
		free(ptr);
	ft_printf("An error has occured.\n");
	exit(EXIT_FAILURE);
}

long double	ft_atold(char *str)
{
	int			i;
	long double	sign;
	long double	ans;

	i = 0;
	sign = 1;
	ans = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		ans = ans * 10 + (long double)(str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		ans = ft_atold_2(str, i + 1, sign, ans);
	else if (str[i] != '\0' || ans > 2 || str[0] == '\0')
		return (10);
	return (ans);
}

long double	ft_atold_2(char *str, int i, int sign, long double ans)
{
	int	div;

	div = 10;
	while (str[i] >= '0' && str[i] <= '9' && i < 6 && str[i] != '\0')
	{
		ans = ans + (long double)(str[i] - 48) / div;
		i++;
		div *= 10;
	}
	if (str[i] != '\0' || ans > 2)
		return (10);
	return (ans * sign);
}
