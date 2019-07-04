/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:09:46 by kmira             #+#    #+#             */
/*   Updated: 2019/07/03 22:36:33 by kmira            ###   ########.fr       */
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

#define VP void*
#define PARAMS(sec) (VP)app->image_address, (VP)camera, (VP)pixel_array, (VP)(sec)

int		render(void **params)
{
	t_app		*app;
	t_camera	*camera;
	t_pixel		**pixel_array;
	t_keys		*key_table;
	t_key_flags	pressed_keys;
	pthread_t	thread_id[10];

	app = params[APPLICATION];
	camera = params[CAMERA];
	pixel_array = params[PIXEL_ARRAY];
	key_table = params[KEY_DISPATCH_TABLE];
	pressed_keys = *(t_key_flags *)params[KEYS_PRESSED];
	if (pressed_keys & KEY_ESC)
		close_application(params);
	set_translate(&pressed_keys, camera);
	set_zoom(params[KEYS_PRESSED], camera);
	transform_points(pixel_array, camera);


	pthread_create(&thread_id[0], NULL, &color_gradient, (void*[4]){PARAMS(0)});
	pthread_create(&thread_id[1], NULL, &color_gradient, (void*[4]){PARAMS(100)});
	pthread_create(&thread_id[2], NULL, &color_gradient, (void*[4]){PARAMS(200)});
	pthread_create(&thread_id[3], NULL, &color_gradient, (void*[4]){PARAMS(300)});
	pthread_create(&thread_id[4], NULL, &color_gradient, (void*[4]){PARAMS(400)});
	pthread_create(&thread_id[5], NULL, &color_gradient, (void*[4]){PARAMS(500)});
	pthread_create(&thread_id[6], NULL, &color_gradient, (void*[4]){PARAMS(600)});
	pthread_create(&thread_id[7], NULL, &color_gradient, (void*[4]){PARAMS(700)});
	pthread_create(&thread_id[8], NULL, &color_gradient, (void*[4]){PARAMS(800)});
	pthread_create(&thread_id[9], NULL, &color_gradient, (void*[4]){PARAMS(900)});
	pthread_join(thread_id[0], NULL);
	pthread_join(thread_id[1], NULL);
	pthread_join(thread_id[2], NULL);
	pthread_join(thread_id[3], NULL);
	pthread_join(thread_id[4], NULL);
	pthread_join(thread_id[5], NULL);
	pthread_join(thread_id[6], NULL);
	pthread_join(thread_id[7], NULL);
	pthread_join(thread_id[8], NULL);
	pthread_join(thread_id[9], NULL);
	mlx_clear_window(app->mlx_connection, app->window);
	mlx_put_image_to_window(app->mlx_connection, app->window, app->image, 0, 0);
	return (1);
}
