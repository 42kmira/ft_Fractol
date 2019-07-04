/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:33:32 by kmira             #+#    #+#             */
/*   Updated: 2019/07/03 05:07:23 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_camera	create_camera(void)
{
	t_camera camera;

	camera.pos[X] = 0;
	camera.pos[Y] = 0;
	camera.scaling = 5400000;
	camera.real_constant = 0.285;
	camera.imaginary_constant = 0.01;
	camera.type = 'M';
	camera.color_type = 1;
	return (camera);
}
