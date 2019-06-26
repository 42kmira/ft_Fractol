/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:33:54 by kmira             #+#    #+#             */
/*   Updated: 2019/06/26 02:52:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define CONSTANT 1
#define UNIT (float)2000

int		distance_to_origin(int x, int y)
{
	int result;

	x = x / ZOOM_STEPS;
	y = y / ZOOM_STEPS;
	result = x * x + y * y;
	result = (int)sqrt(result);
	return (result);
}

int		points_converge(float real_value, float imaginary_value, int print, float actual_real, float actual_imaginary)
{
	float result;

	if (-2 < 2 * imaginary_value * real_value + actual_imaginary && 2 * imaginary_value * real_value + actual_imaginary < 2)
	{
		result = real_value * real_value - imaginary_value * imaginary_value + actual_real;
		if (print && DEBUG)
		{
			printf(" VAL1: (%.1f, %.1f)",
			result,
			2 * imaginary_value * real_value + actual_imaginary);
			print++;
		}
		if (-2 < result && result < 2)
			return (1);
	}
	if (print && DEBUG)
		printf(" VAL2: (%.1f, %.1f)",
		real_value * real_value - imaginary_value * imaginary_value + actual_imaginary,
		2 * imaginary_value * real_value + imaginary_value);
	(void)print;
	return (0);
}

int		fractal_function(int real_value, int imaginary_value, int print)
{
	int		result;
	int		record;
	float	real_value_copy;
	float	imaginary_value_copy;
	float	real_value_copy_copy;

	result = 0;

	record = 0;
	real_value_copy = real_value / UNIT;
	imaginary_value_copy = imaginary_value / UNIT;
	while (real_value_copy * real_value_copy + imaginary_value_copy * imaginary_value_copy < 4 && result < 20)
	{
		if (points_converge(real_value_copy, imaginary_value_copy, print, real_value / UNIT, imaginary_value / UNIT) == 0)
		{
			return (result * 10);
		}
		real_value_copy_copy = real_value_copy;
		real_value_copy = real_value_copy * real_value_copy - imaginary_value_copy * imaginary_value_copy + real_value / UNIT;
		imaginary_value_copy = 2 * real_value_copy_copy * imaginary_value_copy + imaginary_value / UNIT;
		result++;
	}
	return (result * 10);
}

void	color_gradient(char *image_address, t_pixel **pixel_array)
{
	size_t	i;
	size_t	j;
	size_t	row;
	size_t	col;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		row = i * (WINDOW_WIDTH * BYTES_PER_PIXEL);
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			col = j * BYTES_PER_PIXEL;
			// printf("ACTUAL: (%zu, %zu) TRANSFORMED: (%d, %d)\n", j, i, pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value);
			// image_address[row + col + 2] = (char)distance_to_origin(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value);
			// image_address[row + col + 1] = (char)distance_to_origin(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value);
			// image_address[row + col + 0] = (char)distance_to_origin(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value);

			if (DEBUG)
				printf("AT: (%.1f, %.1f)", pixel_array[i][j].real_value / UNIT, pixel_array[i][j].imaginary_value/ UNIT);

			image_address[row + col + 2] = (char)fractal_function(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value, 1);
			image_address[row + col + 1] = (char)fractal_function(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value, 0);
			image_address[row + col + 0] = (char)fractal_function(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value, 0);

			if (-.001 < pixel_array[i][j].real_value && pixel_array[i][j].real_value < .001)
				image_address[row + col + 2] = (char)0xFF;
			if (-.001 < pixel_array[i][j].imaginary_value && pixel_array[i][j].imaginary_value < .001)
				image_address[row + col + 2] = (char)0xFF;

			if (DEBUG)
				printf("\n");

			if (-.008 + 1 < pixel_array[i][j].real_value / UNIT && pixel_array[i][j].real_value / UNIT < .008 + 1)
				image_address[row + col + 1] = (char)0xFF;
			if (-.008 - 1 < pixel_array[i][j].real_value / UNIT && pixel_array[i][j].real_value / UNIT < .008 - 1)
				image_address[row + col + 1] = (char)0xFF;
			if (-.008 - 1 < pixel_array[i][j].imaginary_value / UNIT && pixel_array[i][j].imaginary_value / UNIT < .008 - 1)
				image_address[row + col + 1] = (char)0xFF;
			if (-.008 + 1 < pixel_array[i][j].imaginary_value / UNIT && pixel_array[i][j].imaginary_value / UNIT < .008 + 1)
				image_address[row + col + 1] = (char)0xFF;
			j++;
		}
		i++;
	}
}
