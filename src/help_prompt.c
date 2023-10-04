/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadanow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:32:03 by asadanow          #+#    #+#             */
/*   Updated: 2023/02/04 16:32:05 by asadanow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_vars	init_prompt(void)
{
	t_vars	vars;
	char	buffer[100];

	buffer[0] = 0;
	ft_printf("\nSelect a fractal set :\n\x1B[32m[1]\x1B[0m Julia   \x1B[32m");
	ft_printf("[2]\x1B[0m Mandelbrot   \x1B[32m[3]\x1B[0m Burning Ship\n");
	while (!(buffer[0] > 48 && buffer[0] < 52))
	{
		if (read(0, buffer, 100) == -1)
			error_exit(NULL);
		else if (!(buffer[0] > 48 && buffer[0] < 52))
			ft_printf("\x1B[31mPlease input a correct number.\x1B[0m\n");
	}
	vars.type = buffer[0] - 48;
	if (vars.type == 1)
		vars = get_julia_coord(vars, buffer);
	else
	{
		vars.coord[0] = 0.5;
		vars.coord[1] = 0.5;
	}
	vars = fill_rest(vars);
	vars.color = get_colorway(buffer);
	return (vars);
}

t_vars	get_julia_coord(t_vars vars, char buffer[100])
{
	ft_printf("\nJulia parameters :\n");
	ft_printf("Enter two numbers between -2 and 2\n");
	buffer[0] = '\0';
	vars.coord[0] = get_julia_coord_2(buffer, 'x');
	vars.coord[1] = get_julia_coord_2(buffer, 'y');
	return (vars);
}

long double	get_julia_coord_2(char buffer[100], char axis)
{
	int			rd;
	long double	coord;

	while (ft_atold(buffer) == 10)
	{
		ft_printf("%c = ", axis);
		rd = read(0, buffer, 100);
		if (rd == -1)
			error_exit(NULL);
		buffer[rd - 1] = '\0';
		if (ft_atold(buffer) == 10)
			ft_printf("\n\x1B[31mPlease input a correct number.\x1B[0m\n");
	}
	coord = ft_atold(buffer);
	buffer[0] = '\0';
	return (coord);
}

int	get_colorway(char buffer[100])
{
	buffer[0] = 0;
	ft_printf("\nSelect a colorway :\n\x1B[32m[1]\x1B[0m Blue  \x1B[32m");
	ft_printf("[2]\x1B[0m Red  \x1B[32m[3]\x1B[0m Beige  \x1B[32m[4]");
	ft_printf("\x1B[0m Grey\n");
	while (!(buffer[0] > 48 && buffer[0] < 53))
	{
		if (read(0, buffer, 100) == -1)
			error_exit(NULL);
		else if (!(buffer[0] > 48 && buffer[0] < 53))
			ft_printf("\x1B[31mPlease input a correct number.\x1B[0m\n");
	}
	return (buffer[0] - 48);
}

void	print_cmds(void)
{
	ft_printf("\n\x1B[36m// HOW TO LAUNCH \\\\\x1B[33m\n\nNo args:\x1B[0m ");
	ft_printf("interactive\n\n\x1B[33mArg 1: \x1B[0mfractal type (\x1B[35m'j");
	ft_printf("ulia'\x1B[0m - \x1B[35m'mandelbrot'\x1B[0m - \x1B[35m'burning");
	ft_printf("ship'\x1B[0m)\n\n\x1B[33mArg 2 & 3 (julia only):\x1B[0m Numbe");
	ft_printf("rs between -2 and 2\n\n\x1B[36m// COMMANDS \\\\\x1B[33m\n\nAr");
	ft_printf("row Keys:\x1B[0m Movement\n\n\x1B[33mWASD:\x1B[0m Change Para");
	ft_printf("meters (julia only)\n\n\x1B[33m1 - 4:\x1B[0m Change Colorway");
	ft_printf("\n\n\x1B[33m+ & -:\x1B[0m Change Max Iterations");
	ft_printf("\n\n\x1B[33mScroll Wheel:\x1B[0m Zoom in/out\n\n");
	ft_printf("\x1B[33mRight Click:\x1B[0m Big Zoom\n\n");
	ft_printf("\x1B[33mEscape: \x1B[0mExit Program\n\n");
	exit(EXIT_SUCCESS);
}
