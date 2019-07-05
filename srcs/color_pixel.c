/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:33:54 by kmira             #+#    #+#             */
/*   Updated: 2019/07/04 19:04:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define UNIT (long double)1500000000

#include <pthread.h>

int		fractal_function
	(long double real_value, long double imaginary_value, t_camera *camera)
{
	int			result;
	long double	a;
	long double	b_copy;
	long double	a_copy;

	result = 0;
	a = real_value / UNIT;
	b_copy = imaginary_value / UNIT;
	if (camera->type != 'M' && camera->type != 'C')
	{
		real_value = 0;
		imaginary_value = 0;
	}
	while (a * a + b_copy * b_copy < 2 && result < 125)
	{
		a_copy = a;
		a = a * a - b_copy * b_copy + camera->real_constant + real_value / UNIT;
		if (camera->type == 'C')
			b_copy = fabsl(2 * a_copy * b_copy) + imaginary_value / UNIT;
		else
			b_copy = 2 * a_copy * b_copy + camera->imaginary_constant
			+ imaginary_value / UNIT;
		result++;
	}
	return (result * 2);
}

#define PIXEL_ROW i * (WINDOW_WIDTH * BYTES_PER_PIXEL)
#define PIXEL_COL j * BYTES_PER_PIXEL

void	*color_pixel(void *param)
{
	int			i;
	size_t		j;
	char		iter;
	t_pixel		**pixel_array;
	void		**params;

	params = param;
	pixel_array = params[PIXEL_ARRAY];
	i = (int)params[SECT];
	while (i < (int)params[SECT] + 100)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			iter = (char)fractal_function(
				pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value,
				(t_camera *)params[CAMERA]);
			set_color((char *)params[IMG_ADDR],
				PIXEL_ROW + PIXEL_COL,
				iter, (t_camera *)params[CAMERA]);
			j++;
		}
		i++;
	}
	return (NULL);
}
