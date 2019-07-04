/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:33:54 by kmira             #+#    #+#             */
/*   Updated: 2019/07/03 05:11:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define UNIT (long double)1500000000

#include <pthread.h>

int		fractal_function(int real_value, int imaginary_value, t_camera *camera)
{
	int		result;
	long double	a;
	long double	b_copy;
	long double	a_copy;
	long double	m_set_real;
	long double	m_set_imaginary;

	m_set_real = 0;
	m_set_imaginary = 0;
	if (camera->type == 'M' || camera->type == 'C')
	{
		m_set_real = real_value / UNIT;
		m_set_imaginary = imaginary_value / UNIT;
	}
	result = 0;
	a = real_value / UNIT;
	b_copy = imaginary_value / UNIT;
	while (a * a + b_copy * b_copy < 2 && result < 125)
	{
		a_copy = a;
		a = a * a - b_copy * b_copy + camera->real_constant + m_set_real;
		if (camera->type == 'C')
			b_copy = fabsl(2 * a_copy * b_copy) + m_set_imaginary;
		else
			b_copy = 2 * a_copy * b_copy + camera->imaginary_constant + m_set_imaginary;
		result++;
	}
	return (result * 2);
}

void	*color_gradient(void *param)
{
	int			i;
	size_t		j;
	size_t		row;
	size_t		col;
	char		iter;
	char		*image_address;
	t_pixel		**pixel_array;
	t_camera	*camera;
	void		**params = param;


	image_address = params[IMG_ADDR];
	camera = params[CAMERA];
	pixel_array = params[PIXEL_ARRAY];
	i = (int)params[SECT];
	while (i < (int)params[SECT] + 100)
	{
		row = i * (WINDOW_WIDTH * BYTES_PER_PIXEL);
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			col = j * BYTES_PER_PIXEL;
			iter = (char)fractal_function(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value, camera);
			if (camera->color_type == 1)
			{
				image_address[row + col + 2] = (char)((.00000054) * (iter) * (iter - 40) * (iter - 40) * (iter - 255));
				image_address[row + col + 1] = (char)((.00002) * (iter) * (iter - 255) * ((.027) * iter * iter));
				image_address[row + col + 0] = (char)((.00000000024) * (iter * iter) * (iter - 110) * (iter - 110) * (iter - 255) * (iter - 255));
			}
			else
			{
				image_address[row + col + 2] = (char)((175) / (powf(2, (iter - 125) * (iter - 125) * (.004)))) + ((70) / (powf(2, (iter - 125) * (iter - 125) * (.0004))));;
				image_address[row + col + 1] = (char)((150) / (powf(2, (iter - 125) * (iter - 125) * (.0005)))) - ((120) / (powf(2, (iter - 125) * (iter - 125) * (.004))));
				image_address[row + col + 0] = (char)((160) / (powf(2, (iter - 125) * (iter - 125) * (.0005)))) + iter / (float)2;
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
