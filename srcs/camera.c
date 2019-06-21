/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:33:32 by kmira             #+#    #+#             */
/*   Updated: 2019/06/21 12:18:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_camera	create_camera(void)
{
	t_camera camera;

	camera.pos[X] = 200;
	camera.pos[Y] = 70;
	camera.constant = 2;
	camera.scaling[X] = 1;
	camera.scaling[Y] = 1;
	return (camera);
}
