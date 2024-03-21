/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:45 by yaboulan          #+#    #+#             */
/*   Updated: 2024/03/21 05:14:48 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	scale_number(double num, double old_max, double old_min, int test)
{
	if (test == 1)
		return ((2 - (-2)) * (num - old_min) / (old_max - old_min) + (-2));
	else
		return ((-2 - (2)) * (num - old_min) / (old_max - old_min) + (2));
}

double	ft_atoi(char *nmbr)
{
	int		signe;
	int		result;
	double	part_fract;
	double	flotant_part;

	signe = 1;
	result = 0;
	part_fract = 0.0;
	flotant_part = 0.1;
	while (*nmbr == ' ' || *nmbr == '\t')
		nmbr++;
	if (*nmbr == '-')
	{
		signe *= -1;
		nmbr++;
	}
	func(&nmbr, &result, &part_fract);
	return (signe * (result + part_fract));
}

void	init_data(int argc, char **argv, t_data *param)
{
	param->max_iterations = 50;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, 1500, 1500, "Hello world!");
	param->img_width = 1500;
	param->img_height = 1500;
	param->zoom_factor = 1.0;
	param->img = mlx_new_image(param->mlx, param->img_width, param->img_height);
	param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel,
			&param->line_length, &param->endian);
	check_args(argc, argv, param);
}

void	check_args(int argc, char **argv, t_data *img)
{
	if (argc == 2 && ft_strcmp(argv[1], "mandelbrot"))
	{
		img->name = "mandelbrot";
		render_mandelbrot(img);
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia") && check_julia(argv))
	{
		img->name = "julia";
		img->c_reel = ft_atoi(argv[2]);
		img->imaginary = ft_atoi(argv[3]);
		render_julia(img);
	}
	else if (argc == 2 && ft_strcmp(argv[1], "burning"))
	{
		img->name = "burning";
		render_burning(img);
	}
	else
	{
		write(1, "please enter mandelbrot or julia \n", 34);
		exit(1);
	}
}
