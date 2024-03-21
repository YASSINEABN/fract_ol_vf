/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_Mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:58:07 by yaboulan          #+#    #+#             */
/*   Updated: 2024/03/21 05:13:56 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	render(t_cr crr, int x, int y, t_data *img)
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
		z.y = 2 * z.temp * z.y + crr.y;
		if ((z.x * z.x + z.y * z.y) > 4)
		{
			color = ((0x000000 - (0x363636)) * (j - 0) / (img->max_iterations
						- 0) + (0x363636));
			my_mlx_pixel_put(img, x, y, color);
			return ;
		}
	}
	my_mlx_pixel_put(img, x, y, 0x000000);
}

void	render_mandelbrot(t_data *param)
{
	int		y;
	int		x;
	t_cr	t_cr;

	param->img = mlx_new_image(param->mlx, 1500, 1500);
	param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel,
			&param->line_length, &param->endian);
	y = -1;
	x = -1;
	while (++y < 1500)
	{
		x = 0;
		while (++x < 1500)
		{
			t_cr.x = scale_number(x, 1500 * param->zoom_factor, 0, 1)
				+ (param->x_shift * param->zoom_factor);
			t_cr.y = scale_number(y, 0, 1500 * param->zoom_factor, 0)
				+ param->y_shift * param->zoom_factor;
			render(t_cr, x, y, param);
		}
	}
}
