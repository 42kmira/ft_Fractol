/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:41:34 by kmira             #+#    #+#             */
/*   Updated: 2019/07/03 22:48:54 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_keys	*get_key_table(void)
{
	t_keys *key_dispatch;

	key_dispatch = malloc(sizeof(*key_dispatch) * (8));
	key_dispatch[0] = (t_keys){123, KEY_UP};
	key_dispatch[1] = (t_keys){124, KEY_DOWN};
	key_dispatch[2] = (t_keys){125, KEY_LEFT};
	key_dispatch[3] = (t_keys){126, KEY_RIGHT};
	key_dispatch[4] = (t_keys){6, KEY_ZOOM_IN};
	key_dispatch[5] = (t_keys){7, KEY_ZOOM_OUT};
	key_dispatch[6] = (t_keys){53, KEY_ESC};
	key_dispatch[7] = (t_keys){0, UNDEFINED_KEY};
	return (key_dispatch);
}

t_app	create_application(void)
{
	t_app	app;

	app.mlx_connection = mlx_init();
	app.window = mlx_new_window(
		app.mlx_connection,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		WINDOW_NAME);
	app.image = mlx_new_image(
		app.mlx_connection,
		WINDOW_WIDTH,
		WINDOW_HEIGHT);
	app.image_address = mlx_get_data_addr(
		app.image,
		(int[1]){BYTES_PER_PIXEL},
		(int[1]){WINDOW_WIDTH * BYTES_PER_PIXEL},
		(int[1]){0});
	return (app);
}

int		mouse_move(int x, int y, void **params)
{
	t_camera	*camera;
	t_key_flags	*keys_pressed;

	camera = params[CAMERA];
	keys_pressed = params[KEYS_PRESSED];
	if (!(FREEZE & *keys_pressed))
	{
		camera->real_constant = x / (float)WINDOW_HEIGHT;
		camera->imaginary_constant = y / (float)WINDOW_WIDTH;
	}
	return (1);
}

int		mouse_pressed(int key, int x, int y, void **params)
{
	t_key_flags	*keys_pressed;

	keys_pressed = params[KEYS_PRESSED];
	if (key == 4)
		*keys_pressed = *keys_pressed | WHEEL_UP;
	if (key == 5)
		*keys_pressed = *keys_pressed | WHEEL_DOWN;
	(void)x;
	(void)y;
	return (1);
}

#define VP (void *)
#define PARAMS VP app, VP camera, VP pixel_array, VP key_table, VP &pressed_keys

void	application_loop(t_app *app, t_camera *camera, t_pixel **pixel_array)
{
	t_keys		*key_table;
	t_key_flags	pressed_keys;

	pressed_keys = 0;
	key_table = get_key_table();
	mlx_hook(app->window, 2, 0, switch_key_flag_on, (void*[5]){PARAMS});
	mlx_hook(app->window, 3, 0, switch_key_flag_off, (void*[5]){PARAMS});
	mlx_hook(app->window, 4, 0, mouse_pressed, (void*[5]){PARAMS});
	mlx_hook(app->window, 6, 0, mouse_move, (void*[5]){PARAMS});
	mlx_loop_hook(app->mlx_connection, &render, (void*[5]){PARAMS});
	mlx_loop(app->mlx_connection);
}
