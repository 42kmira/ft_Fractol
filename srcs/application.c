/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:41:34 by kmira             #+#    #+#             */
/*   Updated: 2019/06/21 14:24:47 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include "transport.c"

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

void	application_loop(t_app *app, t_pixel **pixel_array, t_camera *camera)
{
	transform_points(pixel_array, camera);
	color_gradient(app->image_address, pixel_array);
	mlx_put_image_to_window(app->mlx_connection, app->window, app->image, 0, 0);

	mlx_loop(app->mlx_connection);
}
