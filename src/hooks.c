/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:32:08 by asadanow          #+#    #+#             */
/*   Updated: 2023/02/04 16:32:15 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode > 65360 && keycode < 65365)
		return (arrow_movement(keycode, vars));
	else if (keycode == 97 || keycode == 100
		|| keycode == 119 || keycode == 115)
		return (julia_change(keycode, vars));
	else if (keycode == 61 || keycode == 45)
		return (max_iter_change(keycode, vars));
	else if (keycode == 65307)
		return (win_close(vars, 0));
	else if (keycode == 49)
		vars->color = 1;
	else if (keycode == 50)
		vars->color = 2;
	else if (keycode == 51)
		vars->color = 3;
	else if (keycode == 52)
		vars->color = 4;
	put_fractal_img(vars, 1);
	return (0);
}

int	arrow_movement(int keycode, t_vars *vars)
{
	if (keycode == 65361)
		vars->ld_xy[0] -= (long double)(10 * vars->increm);
	if (keycode == 65363)
		vars->ld_xy[0] += (long double)(10 * vars->increm);
	if (keycode == 65362)
		vars->ld_xy[1] -= (long double)(10 * vars->increm);
	if (keycode == 65364)
		vars->ld_xy[1] += (long double)(10 * vars->increm);
	put_fractal_img(vars, 1);
	return (0);
}

int	julia_change(int keycode, t_vars *vars)
{
	if (keycode == 97)
		vars->coord[0] -= (long double)0.02;
	else if (keycode == 100)
		vars->coord[0] += (long double)0.02;
	if (keycode == 119)
		vars->coord[1] -= (long double)0.02;
	else if (keycode == 115)
		vars->coord[1] += (long double)0.02;
	put_fractal_img(vars, 1);
	return (0);
}

int	max_iter_change(int keycode, t_vars *vars)
{
	if (keycode == 61)
	{
		if (vars->max_iter < 600)
		{
			vars->max_iter += 50;
			ft_printf("Maximum iterations set to %d\n", vars->max_iter);
			put_fractal_img(vars, 1);
		}
		else
			ft_printf("\x1B[31mMaximum iterations reached.\x1B[0m\n");
	}
	else if (keycode == 45)
	{
		if (vars->max_iter > 100)
		{
			vars->max_iter -= 50;
			ft_printf("Maximum iterations set to %d\n", vars->max_iter);
			put_fractal_img(vars, 1);
		}
		else
			ft_printf("\x1B[31mMinimum iterations reached.\x1B[0m\n");
	}
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == 4)
	{
		vars->center[0] = (long double)(x);
		vars->center[1] = (long double)(y);
		put_fractal_img(vars, 0.9);
	}
	else if (keycode == 5)
	{
		vars->center[0] = (long double)(x);
		vars->center[1] = (long double)(y);
		put_fractal_img(vars, 1.1);
	}
	else if (keycode == 3)
	{
		vars->center[0] = (long double)(x);
		vars->center[1] = (long double)(y);
		put_fractal_img(vars, 0.4);
	}
	return (0);
}
