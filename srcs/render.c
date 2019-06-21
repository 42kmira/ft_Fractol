/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 23:09:46 by kmira             #+#    #+#             */
/*   Updated: 2019/06/21 12:19:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	translate_point(t_pixel *pixel_point, t_camera *camera)
{
	pixel_point->real_value = pixel_point->real_value + camera->pos[X];
	pixel_point->imaginary_value = pixel_point->imaginary_value + camera->pos[I];
}

void	transform_points(t_pixel **pixel_arr, t_camera *camera)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			// print_pixel_loc(&pixel_arr[i][j], 0);
			translate_point(&pixel_arr[i][j], camera);
			// print_pixel_loc(&pixel_arr[i][j], 1);
			j++;
		}
		i++;
	}
}
