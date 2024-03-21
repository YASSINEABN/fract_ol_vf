/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:25:25 by yaboulan          #+#    #+#             */
/*   Updated: 2024/03/21 05:07:45 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int	test(int keycode, t_data *param)
{
	if (keycode == 53)
		ft_close(param);
	if (keycode == 124)
		param->x_shift -= 0.5 / (param->zoom_factor + 1);
	else if (keycode == 123)
		param->x_shift += 0.5 / (param->zoom_factor + 1);
	else if (keycode == 126)
		param->y_shift += 0.5 / (param->zoom_factor + 1);
	else if (keycode == 125)
		param->y_shift -= 0.5 / (param->zoom_factor + 1);
	else if (keycode == 24)
		param->max_iterations += 15;
	else if (keycode == 27)
		param->max_iterations -= 15;
	if (ft_strcmp(param->name, "mandelbrot"))
		render_mandelbrot(param);
	else if (ft_strcmp(param->name, "burning"))
		render_burning(param);
	else
		render_julia(param);
	mlx_clear_window(param->mlx, param->win);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *param)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		param->zoom_factor *= 1.2;
	else if (keycode == 5)
		param->zoom_factor /= 1.2;
	if (ft_strcmp(param->name, "mandelbrot"))
		render_mandelbrot(param);
	else if (ft_strcmp(param->name, "burning"))
		render_burning(param);
	else
		render_julia(param);
	mlx_clear_window(param->mlx, param->win);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}

int	ft_close(t_data *param)
{
	mlx_destroy_image(param->mlx, param->img);
	mlx_clear_window(param->mlx, param->win);
	mlx_destroy_window(param->mlx, param->win);
	exit(1);
}

int	ft_strcmp(char *str, char *str2)
{
	while (*str == *str2 && *str && *str2)
	{
		str++;
		str2++;
	}
	if (*str != *str2)
		return (0);
	return (1);
}

void	func(char **nmbr, int *result, double *part_fract)
{
	double	flotant_part;

	flotant_part = 0.1;
	while (**nmbr && **nmbr != '.')
	{
		*result = (*result * 10) + (**nmbr - 48);
		(*nmbr)++;
	}
	if (**nmbr == '.')
	{
		(*nmbr)++;
		while (**nmbr)
		{
			*part_fract += (**nmbr - 48) * flotant_part;
			flotant_part *= 0.1;
			(*nmbr)++;
		}
	}
}
