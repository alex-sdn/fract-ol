/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:58:14 by asadanow          #+#    #+#             */
/*   Updated: 2023/01/30 12:58:16 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	win_close(t_vars *vars, int error)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	if (error == 1)
	{
		ft_printf("An error has occured.\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

t_vars	init_vars(int ac, char **av)
{
	t_vars	vars;

	vars.type = get_type(av[1]);
	if (ft_strncmp(av[1], "julia", 5) == 0)
		vars.type = 1;
	else if (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		vars.type = 2;
	else if (ft_strncmp(av[1], "burningship", 11) == 0)
		vars.type = 3;
	else
		vars.type = 0;
	if (ac >= 4)
	{
		vars.coord[0] = ft_atold(av[2]);
		vars.coord[1] = ft_atold(av[3]);
		if (vars.coord[0] == 10 || vars.coord[1] == 10)
			vars.type = 0;
	}
	else
	{
		vars.coord[0] = 0.5;
		vars.coord[1] = 0.5;
	}
	vars = fill_rest(vars);
	return (vars);
}

int	get_type(char *arg1)
{
	if (ft_strncmp(arg1, "help", 4) == 0)
		print_cmds();
	if (ft_strncmp(arg1, "julia", 5) == 0)
		return (1);
	else if (ft_strncmp(arg1, "mandelbrot", 10) == 0)
		return (2);
	else if (ft_strncmp(arg1, "burningship", 11) == 0)
		return (3);
	else
		return (0);
}

t_vars	fill_rest(t_vars vars)
{
	vars.center[0] = 400;
	vars.center[1] = 400;
	vars.ld_xy[0] = -2;
	vars.ld_xy[1] = -2;
	vars.increm = 4 / (long double)800;
	vars.color = 1;
	if (vars.type == 1)
		vars.max_iter = 200;
	else if (vars.type == 2 || vars.type == 3)
		vars.max_iter = 150;
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 1)
		vars = init_prompt();
	else if (ac > 1)
		vars = init_vars(ac, av);
	if (vars.type == 0)
	{
		ft_printf("\x1B[31mPlease input correct parameters.\x1B[0m (");
		ft_printf("\x1B[35m'./fractol help'\x1B[0m)\n");
		return (1);
	}
	vars.mlx_ptr = mlx_init();
	if (vars.mlx_ptr == NULL)
		error_exit(NULL);
	vars.win_ptr = mlx_new_window(vars.mlx_ptr, 800, 800, "fractol");
	if (vars.win_ptr == NULL)
		error_exit(vars.mlx_ptr);
	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	mlx_mouse_hook(vars.win_ptr, mouse_hook, &vars);
	mlx_hook(vars.win_ptr, 17, 0, &win_close, &vars);
	put_fractal_img(&vars, 1);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
