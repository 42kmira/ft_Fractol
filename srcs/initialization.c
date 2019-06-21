/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:53:39 by kmira             #+#    #+#             */
/*   Updated: 2019/06/20 22:10:49 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel	**create_pixel_array(void)
{
	size_t	i;
	t_pixel	**pixel_array;

	i = 0;
	pixel_array = malloc(sizeof(*pixel_array) * (WINDOW_HEIGHT + 1));
	while (i < WINDOW_HEIGHT)
	{
		pixel_array[i] = malloc(sizeof(**pixel_array) * (WINDOW_WIDTH + 1));
		i++;
	}
	return (pixel_array);
}
