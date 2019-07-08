/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:41:34 by kmira             #+#    #+#             */
/*   Updated: 2019/07/07 22:17:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
