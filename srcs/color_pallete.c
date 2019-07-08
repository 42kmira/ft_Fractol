/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_pallete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:03:41 by kmira             #+#    #+#             */
/*   Updated: 2019/07/07 22:18:50 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Below are equations that have a range of 0 - 255 between domain 0 - 255
** They fetch a value based on the iter passed to them that corresponds to
** a certain RGB channel. It looks tricky because of norm but it is easy to
** understand what they are doing when you make them into one line and graph
** them.
*/

#define CHAMELEON_SKIN 1
#define NEW_RETRO_SKIN 2
#define GRAYSCALE_SKIN 3

void	set_color(char *image_addr, size_t i, char iter, t_camera *camera)
{
	if (camera->color_type == CHAMELEON_SKIN)
	{
		image_addr[i + 2] = (char)((.00000054)
			* (iter) * (iter - 40) * (iter - 40) * (iter - 255));
		image_addr[i + 1] =
			(char)((.00002) * (iter) * (iter - 255) * ((.027) * iter * iter));
		image_addr[i + 0] = (char)((.00000000024) * (iter * iter)
			* (iter - 110) * (iter - 110) * (iter - 255) * (iter - 255));
	}
	else if (camera->color_type == NEW_RETRO_SKIN)
	{
		image_addr[i + 2] = (char)((175) / (powf(2, (iter - 125)
		* (iter - 125) * (.004)))) + (70 / (powf(2, (iter - 125)
		* (iter - 125) * (.0004))));
		image_addr[i + 1] = (char)((150) / (powf(2, (iter - 125) * (iter - 125)
		* (.0005)))) - (120 / (powf(2, (iter - 125) * (iter - 125) * (.004))));
		image_addr[i + 0] = (char)((160) / (powf(2, (iter - 125)
		* (iter - 125) * (.0005)))) + iter / (float)2;
	}
	else if (camera->color_type == GRAYSCALE_SKIN)
	{
		image_addr[i + 2] = (char)iter;
		image_addr[i + 1] = (char)iter;
		image_addr[i + 0] = (char)iter;
	}
}
