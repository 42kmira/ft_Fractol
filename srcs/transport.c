/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:33:54 by kmira             #+#    #+#             */
/*   Updated: 2019/06/27 06:23:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define UNIT (long double)1500000000
#define CR 0.285
#define CI 0.01

#include <pthread.h>

int		fractal_function(int real_value, int imaginary_value, t_camera *camera)
{
	int		result;
	long double	a;
	long double	b_copy;
	long double	a_copy;
	long double	m_set_real;
	long double	m_set_imaginary;
	long double c_set_real;
	long double c_set_imaginary;

	m_set_real = 0;
	m_set_imaginary = 0;
	c_set_real = 1;
	c_set_imaginary = 1;
	if (camera->type == 'M')
	{
		m_set_real = real_value / UNIT;
		m_set_imaginary = imaginary_value / UNIT;
	}
	if (camera->type == 'C')
	{
		c_set_real = real_value / UNIT;
		c_set_imaginary = imaginary_value / UNIT;
	}
	result = 0;
	a = real_value / UNIT;
	b_copy = imaginary_value / UNIT;
	while (a * a + b_copy * b_copy < 2 && result < 255)
	{
		a_copy = a;
		a = a * a - b_copy * b_copy * c_set_real + camera->real_constant + m_set_real;
		b_copy = 2 * a_copy * b_copy * c_set_imaginary + camera->imaginary_constant + m_set_imaginary;
		result++;
	}
	return (result);
}

void	color_gradient(char *image_address, t_pixel **pixel_array, t_camera *camera)
{
	size_t	i;
	size_t	j;
	size_t	row;
	size_t	col;
	char	iter;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		row = i * (WINDOW_WIDTH * BYTES_PER_PIXEL);
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			col = j * BYTES_PER_PIXEL;
			iter = (char)fractal_function(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value, camera);
			image_address[row + col + 2] = (char)((.00000054) * (iter) * (iter - 40) * (iter - 40) * (iter - 255));
			image_address[row + col + 1] = (char)((.00002) * (iter) * (iter - 255) * ((.027) * iter * iter));
			image_address[row + col + 0] = (char)((.00000000024) * (iter * iter) * (iter - 110) * (iter - 110) * (iter - 255) * (iter - 255));
			j++;
		}
		i++;
	}
}
