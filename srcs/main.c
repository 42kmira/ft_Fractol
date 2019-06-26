/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:05:56 by kmira             #+#    #+#             */
/*   Updated: 2019/06/25 20:43:12 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(void)
{
	t_app		app;
	t_pixel		**pixel_array;
	t_camera	camera;

	app = create_application();
	camera = create_camera();
	pixel_array = create_pixel_array();

	application_loop(&app, &camera, pixel_array);

	return (0);
}
