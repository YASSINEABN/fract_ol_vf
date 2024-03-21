/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_burning.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:59 by yaboulan          #+#    #+#             */
/*   Updated: 2024/03/21 05:14:35 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

double	abs_f(double t)
{
	if (t < 0)
		return (-1 * t);
	return (t);
}

void	render_bur(t_cr crr, int x, int y, t_data *img)
{
	int			j;
	t_complex	z;
	double		color;

	z.x = 0.0;
	z.y = 0.0;
	j = -1;
	while (++j < img->max_iterations)
	{
		z.temp = z.x;
		z.x = (z.x * z.x) - (z.y * z.y) + crr.x;
		z.y = abs_f(2 * z.temp * z.y) + crr.y;
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			color = ((0xffffff - (0x363636)) * (j - 0) / (img->max_iterations
						- 0) + (0x363636));
			my_mlx_pixel_put(img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(img, x, y, 0x000000);
}

void	render_burning(t_data *param)
{
	int		x;
	int		y;
	t_cr	t_cr;

	param->img = mlx_new_image(param->mlx, 1500, 1500);
	param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel,
			&param->line_length, &param->endian);
	x = -1;
	y = -1;
	while (++y < 1500)
	{
		x = 0;
		while (++x < 1500)
		{
			t_cr.x = scale_number(x, 1500 * param->zoom_factor, 0, 1)
				+ param->x_shift;
			t_cr.y = scale_number(y, 0, 1500 * param->zoom_factor, 0)
				+ param->y_shift;
			render_bur(t_cr, x, y, param);
		}
	}
}
