/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:53:39 by kmira             #+#    #+#             */
/*   Updated: 2019/07/04 20:49:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel		**create_pixel_array(void)
{
	size_t	i;
	size_t	j;
	t_pixel	**pixel_array;

	i = 0;
	pixel_array = malloc(sizeof(*pixel_array) * (WINDOW_HEIGHT + 1));
	while (i < WINDOW_HEIGHT)
	{
		pixel_array[i] = malloc(sizeof(**pixel_array) * (WINDOW_WIDTH + 1));
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			pixel_array[i][j].pos[X] = j - (WINDOW_HEIGHT / (long double)2);
			pixel_array[i][j].pos[I] = (WINDOW_WIDTH / (long double)2) - i;
			j++;
		}
		i++;
	}
	return (pixel_array);
}

t_camera	create_camera(void)
{
	t_camera camera;

	camera.pos[X] = 0;
	camera.pos[Y] = 0;
	camera.scaling = 5400000;
	camera.real_constant = 0.285;
	camera.imaginary_constant = 0.01;
	camera.type = 'M';
	camera.color_type = 1;
	return (camera);
}
