/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:09:46 by kmira             #+#    #+#             */
/*   Updated: 2019/07/04 20:49:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define VP (void*)
#define PARAMS(sec) VP image_addr, VP camera, VP pixel_array, VP sec

void	multithread_render
	(char *image_addr, t_camera *camera, t_pixel **pixel_array)
{
	pthread_t	thread_id[10];
	size_t		i;

	pthread_create(&thread_id[0], NULL, &color_pixel, (void*[4]){PARAMS(0)});
	pthread_create(&thread_id[1], NULL, &color_pixel, (void*[4]){PARAMS(100)});
	pthread_create(&thread_id[2], NULL, &color_pixel, (void*[4]){PARAMS(200)});
	pthread_create(&thread_id[3], NULL, &color_pixel, (void*[4]){PARAMS(300)});
	pthread_create(&thread_id[4], NULL, &color_pixel, (void*[4]){PARAMS(400)});
	pthread_create(&thread_id[5], NULL, &color_pixel, (void*[4]){PARAMS(500)});
	pthread_create(&thread_id[6], NULL, &color_pixel, (void*[4]){PARAMS(600)});
	pthread_create(&thread_id[7], NULL, &color_pixel, (void*[4]){PARAMS(700)});
	pthread_create(&thread_id[8], NULL, &color_pixel, (void*[4]){PARAMS(800)});
	pthread_create(&thread_id[9], NULL, &color_pixel, (void*[4]){PARAMS(900)});
	i = 0;
	while (i < 10)
	{
		pthread_join(thread_id[i], NULL);
		i++;
	}
}

void	display_menu(void *mlx_connection, void *window)
{
	mlx_string_put(mlx_connection, window, 15, 15, 0x999999,
	"Controls:");
	mlx_string_put(mlx_connection, window, 15, 40, 0x999999,
	"Change Fractal:");
	mlx_string_put(mlx_connection, window, 15, 65, 0x999999,
	"   'M' = Mandelbrot");
	mlx_string_put(mlx_connection, window, 15, 85, 0x999999,
	"   'J' = Julia");
	mlx_string_put(mlx_connection, window, 15, 105, 0x999999,
	"   'C' = Burning Ship");
	mlx_string_put(mlx_connection, window, 15, 130, 0x999999,
	"Camera:");
	mlx_string_put(mlx_connection, window, 15, 155, 0x999999,
	"   Translate: [Arrow Keys]");
	mlx_string_put(mlx_connection, window, 15, 175, 0x999999,
	"   Zoom: [Mouse Wheel]");
	mlx_string_put(mlx_connection, window, 15, 195, 0x999999,
	"   Freeze Parameter: 'F'");
	mlx_string_put(mlx_connection, window, 15, 220, 0x999999,
	"Alternate Color Skin");
	mlx_string_put(mlx_connection, window, 15, 245, 0x999999,
	"   '<'");
}

int		render(void **params)
{
	t_app		*app;
	t_camera	*camera;
	t_pixel		**pixel_array;
	t_key_flags	pressed_keys;

	pressed_keys = *(t_key_flags *)params[KEYS_PRESSED];
	if (pressed_keys & KEY_ESC)
		close_application(params);
	app = params[APPLICATION];
	camera = params[CAMERA];
	pixel_array = params[PIXEL_ARRAY];
	set_translate(&pressed_keys, camera);
	set_zoom(params[KEYS_PRESSED], camera);
	transform_points(pixel_array, camera);
	multithread_render(app->image_address, camera, pixel_array);
	mlx_clear_window(app->mlx_connection, app->window);
	mlx_put_image_to_window(app->mlx_connection, app->window, app->image, 0, 0);
	display_menu(app->mlx_connection, app->window);
	return (1);
}
