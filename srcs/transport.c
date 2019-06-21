/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:33:54 by kmira             #+#    #+#             */
/*   Updated: 2019/06/21 14:25:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		distance_to_origin(int x, int y)
{
	int result;

	result = x * x + y * y;
	result = (int)sqrt(result);
	return (result);
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
			image_address[row + col + 2] = (char)distance_to_origin(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value);
			image_address[row + col + 1] = (char)distance_to_origin(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value);
			image_address[row + col + 0] = (char)distance_to_origin(pixel_array[i][j].real_value, pixel_array[i][j].imaginary_value);
			j++;
		}
		i++;
	}
}
