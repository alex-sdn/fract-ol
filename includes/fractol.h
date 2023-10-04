/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:58:07 by asadanow          #+#    #+#             */
/*   Updated: 2023/01/30 12:58:09 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars {
	void		*mlx_ptr;
	void		*win_ptr;
	int			type;
	long double	center[2];
	long double	coord[2];
	long double	ld_xy[2];
	long double	increm;
	int			color;
	int			max_iter;
}				t_vars;

/*  Libft  */
int			ft_printf(const char *s, ...);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*  main  */
int			win_close(t_vars *vars, int error);
t_vars		init_vars(int ac, char **av);
int			get_type(char *arg1);
t_vars		fill_rest(t_vars vars);
int			main(int ac, char **av);

/*  Help prompt  */
t_vars		init_prompt(void);
t_vars		get_julia_coord(t_vars vars, char buffer[100]);
long double	get_julia_coord_2(char buffer[100], char axis);
int			get_colorway(char buffer[100]);
void		print_cmds(void);

/*  Utils  */
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_trgb(int t, int r, int g, int b);
long double	ft_atold(char *str);
long double	ft_atold_2(char *str, int i, int sign, long double ans);
void		error_exit(void *ptr);

/*  Hooks  */
int			key_hook(int keycode, t_vars *vars);
int			arrow_movement(int keycode, t_vars *vars);
int			julia_change(int keycode, t_vars *vars);
int			max_iter_change(int keycode, t_vars *vars);
int			mouse_hook(int keycode, int x, int y, t_vars *vars);

/*  Fractals  */
void		color_fractal(t_data *img, t_vars *vars, long double zoom);
double		get_iterations(t_vars *vars, long double ld_xy[2]);
double		divergence_julia(long double xy[2], long double j_xy[2], int max);
double		divergence_mandelbrot(long double xy[2], int max_iter);
double		divergence_burningship(long double xy[2], int max_iter);

void		put_fractal_img(t_vars *vars, long double zoom);
void		color_pixel(t_data *img, t_vars *vars, int win_xy[2], double iter);
int			get_gradiant(double i, int color);

/*  Colorways  */
int			color_blue(double i);
int			color_red(double i);
int			color_beige(double i);

#endif