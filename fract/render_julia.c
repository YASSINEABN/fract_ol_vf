/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:58:01 by yaboulan          #+#    #+#             */
/*   Updated: 2024/03/21 05:14:19 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	renderjul(t_complex *z, double x, double y, t_data *img)
{
	double	c_real;
	double	c_imaginary;
	int		j;
	double	color;

	c_real = (img->c_reel);
	c_imaginary = (img->imaginary);
	z->x = scale_number(x, img->img_width * img->zoom_factor, 0, 1)
		+ img->x_shift;
	z->y = scale_number(y, 0, img->img_height * img->zoom_factor, 0)
		+ img->y_shift;
	j = -1;
	while (++j < img->max_iterations)
	{
		z->temp = z->x;
		z->x = (z->x * z->x) - (z->y * z->y) + c_real;
		z->y = 2 * z->temp * z->y + c_imaginary;
		if ((z->x * z->x + z->y * z->y) > 4)
		{
			color = ((0x000000 - (0x363636)) * (j - 0) / (img->max_iterations
						- 0) + (0x363636));
			my_mlx_pixel_put(img, x, y, color);
			return ;
		}
	}
}

void	render_julia(t_data *param)
{
	int			x;
	int			y;
	t_complex	t_complex;

	param->img = mlx_new_image(param->mlx, 1500, 1500);
	param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel,
			&param->line_length, &param->endian);
	x = -1;
	y = -1;
	while (++y < 1500)
	{
		x = 0;
		while (++x < 1500)
			renderjul(&t_complex, x, y, param);
	}
}
