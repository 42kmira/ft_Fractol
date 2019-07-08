/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:54 by kmira             #+#    #+#             */
/*   Updated: 2019/07/07 22:21:47 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

void	close_application(void **params)
{
	t_app		*app;
	t_key_flags	*dispatch_table;
	t_pixel		**pixel_array;
	size_t		i;

	app = params[APPLICATION];
	dispatch_table = params[KEY_DISPATCH_TABLE];
	pixel_array = params[PIXEL_ARRAY];
	free(dispatch_table);
	i = 0;
	printf("MLX %p, WINDOW: %p, ADDR: %p, IMAGE: %p\n", app->mlx_connection, app->window, app->image_address, app->image);
	mlx_destroy_window(app->mlx_connection, app->window);
	mlx_destroy_image(app->mlx_connection, app->image);
	while (i < WINDOW_HEIGHT)
	{
		free(pixel_array[i]);
		pixel_array[i] = NULL;
		i++;
	}
	free(pixel_array);
	EXIT(GREEN"Program closed successfully");
}
