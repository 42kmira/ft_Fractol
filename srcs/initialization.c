/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:53:39 by kmira             #+#    #+#             */
/*   Updated: 2019/06/27 02:08:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel	**create_pixel_array(void)
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
			// pixel_array[i][j].pos[X] = pixel_array[i][j].pos[X] / (WINDOW_HEIGHT / (long double)2);
			// pixel_array[i][j].pos[Y] = pixel_array[i][j].pos[Y] / (WINDOW_WIDTH / (long double)2);

			// printf("(%.4f, %.4f)\n", pixel_array[i][j].pos[X], pixel_array[i][j].pos[Y]);
			j++;
		}
		i++;
	}
	return (pixel_array);
}
