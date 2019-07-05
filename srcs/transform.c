/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 23:21:46 by kmira             #+#    #+#             */
/*   Updated: 2019/07/03 23:26:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	pixel_point->imaginary_value = midpoint->imaginary_value + delta_imaginary;
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
