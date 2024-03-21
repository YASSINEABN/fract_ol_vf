/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboulan <yaboulan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:47:52 by yaboulan          #+#    #+#             */
/*   Updated: 2024/03/21 04:33:53 by yaboulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_width;
	int		img_height;
	double	x_shift;
	double	y_shift;
	char	*name;
	double	c_reel;
	double	imaginary;
	double	zoom_factor;
	int		max_iterations;
}			t_data;

typedef struct t_complex
{
	double	x;
	double	y;
	double	temp;
}			t_complex;

typedef struct t_coordinate
{
	double	x;
	double	y;
}			t_cr;

typedef struct fract
{
	double	shift_x;
	double	shift_y;
	char	*name;
}			t_fr;

int			ft_strcmp(char *str, char *str2);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		scale_number(double num, double old_max, double old_min, int test);
void		render(t_cr crr, int x, int y, t_data *img);
void		render_mandelbrot(t_data *param);
void		renderjul(t_complex *z, double x, double y, t_data *img);
void		render_julia(t_data *param);
int			test(int keycode, t_data *param);
double		ft_atoi(char *nmbr);
int			mouse_hook(int keycode, int x, int y, t_data *param);
void		init_data(int argc, char **argv, t_data *param);
void		check_args(int argc, char **argv, t_data *img);
void		render_bur(t_cr crr, int x, int y, t_data *img);
void		render_burning(t_data *param);
int			ft_close(t_data *param);
void		func(char **nmbr, int *result, double *part_fract);
int			check_julia(char **argv);
int			is_digit(char c);
int			is_signed(char c);

#endif
