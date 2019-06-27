/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:09:46 by kmira             #+#    #+#             */
/*   Updated: 2019/06/27 03:59:57 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "transport.c"

void	translate_point(t_pixel *pixel_point, t_camera *camera)
{
	pixel_point->real_value = pixel_point->pos[X] + camera->pos[X];
	pixel_point->imaginary_value = pixel_point->pos[Y] + camera->pos[Y];
}

void	scale_point(t_pixel *pixel_point, t_camera *camera, t_pixel *midpoint)
{
	long double	delta_real;
	long double	delta_imaginary;


	delta_real = pixel_point->real_value - midpoint->real_value;
	delta_imaginary = pixel_point->imaginary_value - midpoint->imaginary_value;
	delta_real = delta_real * camera->scaling;
	delta_imaginary = delta_imaginary * camera->scaling;
	pixel_point->real_value = midpoint->real_value + delta_real;
	pixel_point->imaginary_value  = midpoint->imaginary_value + delta_imaginary;
}

void	transform_points(t_pixel **pixel_array, t_camera *camera)
{
	size_t	i;
	size_t	j;
	t_pixel	*midpoint;

	i = 0;
	midpoint = &pixel_array[WINDOW_HEIGHT / 2][WINDOW_WIDTH / 2];
	translate_point(midpoint, camera);

	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			translate_point(&pixel_array[i][j], camera);
			scale_point(&pixel_array[i][j], camera, midpoint);
			j++;
		}
		i++;
	}
}

int		render(void **params)
{
	t_app		*app;
	t_camera	*camera;
	t_pixel		**pixel_array;
	t_keys		*key_table;
	t_key_flags	pressed_keys;

	app = params[APPLICATION];
	camera = params[CAMERA];
	pixel_array = params[PIXEL_ARRAY];
	key_table = params[KEY_DISPATCH_TABLE];
	pressed_keys = *(t_key_flags *)params[KEYS_PRESSED];

	// if (pressed_keys & ANY_PRESSED)
	// {
		if (pressed_keys & KEY_ESC)
			close_application(params);
		set_translate(&pressed_keys, camera);
		set_zoom(params[KEYS_PRESSED], camera);
		transform_points(pixel_array, camera);
		color_gradient(app->image_address, pixel_array, camera);
		mlx_clear_window(app->mlx_connection, app->window);
		mlx_put_image_to_window(app->mlx_connection, app->window, app->image, 0, 0);
	// }
	return (1);
}
