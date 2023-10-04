/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:31:25 by asadanow          #+#    #+#             */
/*   Updated: 2023/02/04 16:31:26 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_blue(double i)
{
	int	g;
	int	b;

	if (i < 0.42)
	{
		g = 107 + (i - 0.16) * 528.57;
		b = 203 + (i - 0.16) * 185.71;
		return (create_trgb(0, 32 + (i - 0.16) * 732.14, g, b));
	}
	else if (i < 0.6425)
	{
		g = 255 - (i - 0.42) * 382.02;
		b = 255 - (i - 0.42) * 1146.06;
		return (create_trgb(0, 237 + (i - 0.42) * 80.89, g, b));
	}
	else if (i < 0.8575)
	{
		g = 170 - (i - 0.6425) * 781.39;
		return (create_trgb(0, 255 - (i - 0.6425) * 1186.04, g, 0));
	}
	else
	{
		g = 2 + (i - 0.8575) * 23.25;
		return (create_trgb(0, 0, g, (i - 0.8575) * 465.11));
	}
}

int	color_red(double i)
{
	int	g;

	if (i < 0.06)
		return (create_trgb(0, i * 3000, 0, 0));
	else if (i < 0.16)
		return (create_trgb(0, 180 + (i - 0.06) * 400, i * 937.5, 0));
	else if (i < 0.6)
	{
		g = 150 - (i - 0.15) * 125.29;
		return (create_trgb(0, 220 + (i - 0.15), g, 0));
	}
	else
	{
		g = 230 - (i - 0.6) * 575;
		return (create_trgb(0, 254 - (i - 0.6) * 635, g, 0));
	}
}

int	color_beige(double i)
{
	int	g;

	if (i < 0.08)
		return (create_trgb(0, 255, 162 + i * 1162.5, 80 + i * 2162.5));
	else if (i < 0.15)
	{
		g = 255 - (i - 0.08) * 857.14;
		return (create_trgb(0, 255, g, 255 - (i - 0.08) * 1285.71));
	}
	else if (i < 0.3)
	{
		g = 195 - (i - 0.15) * 220;
		return (create_trgb(0, 255, g, 165 - (i - 0.15) * 566.66));
	}
	else
		return (create_trgb(0, 255, 162, 80));
}
