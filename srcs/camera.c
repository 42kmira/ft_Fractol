/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:33:32 by kmira             #+#    #+#             */
/*   Updated: 2019/06/25 16:41:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_camera	create_camera(void)
{
	t_camera camera;

	camera.pos[X] = 0;
	camera.pos[Y] = 0;
	camera.constant = 2;
	camera.scaling = ZOOM_STEPS;
	return (camera);
}
