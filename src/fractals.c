/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:31:56 by asadanow          #+#    #+#             */
/*   Updated: 2023/02/04 16:31:57 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_fractal(t_data *img, t_vars *vars, long double zoom)
{
	int			win_xy[2];
	double		iter;
	long double	ld_xy[2];

	win_xy[0] = -1;
	win_xy[1] = -1;
	ld_xy[0] = vars->ld_xy[0] - vars->center[0] * vars->increm * (zoom - 1);
	ld_xy[1] = vars->ld_xy[1] - vars->center[1] * vars->increm * (zoom - 1);
	vars->ld_xy[0] = ld_xy[0];
	vars->ld_xy[1] = ld_xy[1];
	vars->increm *= zoom;
	while (++win_xy[0] < 800)
	{
		while (++win_xy[1] < 800)
		{
			iter = get_iterations(vars, ld_xy);
			color_pixel(img, vars, win_xy, iter);
			ld_xy[1] += vars->increm;
		}
		win_xy[1] = -1;
		ld_xy[1] = vars->ld_xy[1];
		ld_xy[0] += vars->increm;
	}
}

double	get_iterations(t_vars *vars, long double ld_xy[2])
{
	if (vars->type == 1)
		return (divergence_julia(ld_xy, vars->coord, vars->max_iter));
	else if (vars->type == 2)
		return (divergence_mandelbrot(ld_xy, vars->max_iter));
	else if (vars->type == 3)
		return (divergence_burningship(ld_xy, vars->max_iter));
	return (0);
}

double	divergence_julia(long double xy[2], long double j_xy[2], int max)
{
	long double	tmp_x;
	long double	x;
	long double	y;
	double		color;
	int			i;

	i = 0;
	color = 0;
	x = xy[0];
	y = -xy[1];
	while (i < max && (x * x + y * y) < 4)
	{
		tmp_x = x;
		x = (x * x) - (y * y) + j_xy[0];
		y = 2 * tmp_x * y + j_xy[1];
		i++;
		color += exp(-(double)(x * x + y * y));
	}
	if (i == max)
		return (i);
	return (color / (double)max);
}

double	divergence_mandelbrot(long double xy[2], int max_iter)
{
	long double	zx;
	long double	zy;
	long double	tmp_zx;
	double		color;
	int			i;

	zx = 0;
	zy = 0;
	i = 0;
	if ((xy[0] > -0.49 && xy[0] < 0.22) && (xy[1] > -0.49 && xy[1] < 0.49))
		return (max_iter);
	while (i < max_iter && (zx * zx + zy * zy) < 4)
	{
		tmp_zx = zx;
		zx = (zx * zx) - (zy * zy) + xy[0];
		zy = 2 * tmp_zx * zy + xy[1];
		i++;
	}
	if (i == max_iter)
		return (i);
	color = i + 1 - (log(log((double)(zx * zx + zy * zy)))) / log(2);
	return (color / (double)max_iter);
}

double	divergence_burningship(long double xy[2], int max_iter)
{
	long double	zx;
	long double	zy;
	long double	tmp_zx;
	double		color;
	int			i;

	zx = 0;
	zy = 0;
	i = 0;
	while (i < max_iter && (zx * zx + zy * zy) < 5)
	{
		tmp_zx = zx;
		zx = (zx * zx) - (zy * zy) + xy[0];
		zy = 2 * tmp_zx * zy + xy[1];
		i++;
		if (zx < 0)
			zx *= -1;
		if (zy < 0)
			zy *= -1;
	}
	if (i == max_iter)
		return (i);
	color = i + 1 - (log(log((double)(zx * zx + zy * zy)))) / log(2);
	return (color / (double)max_iter);
}
