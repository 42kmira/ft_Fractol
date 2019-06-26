/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:09:46 by kmira             #+#    #+#             */
/*   Updated: 2019/06/26 01:00:01 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "transport.c"

void	translate_point(t_pixel *pixel_point, t_camera *camera)
{
	float real_offset;
	float imaginary_offset;

	real_offset = camera->pos[X] * camera->scaling;
	imaginary_offset = camera->pos[Y] * camera->scaling;

	pixel_point->real_value = pixel_point->real_value + real_offset;
	pixel_point->imaginary_value = pixel_point->imaginary_value  + imaginary_offset;
}

void	scale_point(t_pixel *pixel_point, t_camera *camera)
{
	// printf("SCALE: %f\n", camera->scaling);
	pixel_point->real_value = pixel_point->pos[X] * camera->scaling;
	pixel_point->imaginary_value  = pixel_point->pos[I] * camera->scaling;
}

void	transform_points(t_pixel **pixel_array, t_camera *camera)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			scale_point(&pixel_array[i][j], camera);
			translate_point(&pixel_array[i][j], camera);
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

	if (pressed_keys & ANY_PRESSED)
	{
		if (pressed_keys & KEY_ESC && !DEBUG)
			close_application(params);
		set_translate(&pressed_keys, camera);
		set_zoom(params[KEYS_PRESSED], camera);
		transform_points(pixel_array, camera);
		color_gradient(app->image_address, pixel_array);
		mlx_put_image_to_window(app->mlx_connection, app->window, app->image, 0, 0);
	}
	return (1);
}
