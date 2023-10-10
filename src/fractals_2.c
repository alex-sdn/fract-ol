/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:31:32 by asadanow          #+#    #+#             */
/*   Updated: 2023/02/04 16:31:42 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_fractal_img(t_vars *vars, long double zoom)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx_ptr, 800, 800);
	if (img.img == NULL)
		win_close(vars, 1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	color_fractal(&img, vars, zoom);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img.img, 0, 0);
	mlx_destroy_image(vars->mlx_ptr, img.img);
}

void	color_pixel(t_data *img, t_vars *vars, int win_xy[2], double iter)
{
	if (iter == vars->max_iter && vars->color == 3)
		my_mlx_pixel_put(img, win_xy[0], win_xy[1], 0x00FFFFFF);
	else if (iter == vars->max_iter)
		my_mlx_pixel_put(img, win_xy[0], win_xy[1], 0x00000000);
	else
		my_mlx_pixel_put(img, win_xy[0], win_xy[1],
			get_gradiant(iter, vars->color));
}

int	get_gradiant(double i, int color)
{
	if (color == 1)
	{
		if (i < 0.16)
			return (create_trgb(0, i * 200, 7 + i * 625, 100 + i * 643.75));
		else
			return (color_blue(i));
	}
	else if (color == 2)
		return (color_red(i));
	else if (color == 3)
		return (color_beige(i));
	else if (color == 4)
	{
		if (i < 0.3)
			return (create_trgb(0, i * 850, i * 850, i * 850));
		else
			return (create_trgb(0, 255 - (i - 0.3) * 364.28,
					255 - (i - 0.3) * 364.28, 255 - (i - 0.3) * 364.28));
	}
	return (0);
}
