/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   application_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:07:25 by kmira             #+#    #+#             */
/*   Updated: 2019/07/04 19:25:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_keys	*get_key_table(void)
{
	t_keys *key_dispatch;

	key_dispatch = malloc(sizeof(*key_dispatch) * (8));
	key_dispatch[0] = (t_keys){123, KEY_UP};
	key_dispatch[1] = (t_keys){124, KEY_DOWN};
	key_dispatch[2] = (t_keys){125, KEY_LEFT};
	key_dispatch[3] = (t_keys){126, KEY_RIGHT};
	key_dispatch[4] = (t_keys){6, KEY_ZOOM_IN};
	key_dispatch[5] = (t_keys){7, KEY_ZOOM_OUT};
	key_dispatch[6] = (t_keys){53, KEY_ESC};
	key_dispatch[7] = (t_keys){0, UNDEFINED_KEY};
	return (key_dispatch);
}

void	set_translate(t_key_flags *key_flags, t_camera *camera)
{
	t_key_flags key_pressed;

	key_pressed = *key_flags;
	if (key_pressed & KEY_UP)
		camera->pos[X] += -DELTA_TRANSLATE * camera->scaling;
	if (key_pressed & KEY_DOWN)
		camera->pos[X] += DELTA_TRANSLATE * camera->scaling;
	if (key_pressed & KEY_LEFT)
		camera->pos[Y] += DELTA_TRANSLATE * camera->scaling;
	if (key_pressed & KEY_RIGHT)
		camera->pos[Y] += -DELTA_TRANSLATE * camera->scaling;
}

void	set_zoom(t_key_flags *key_flag, t_camera *camera)
{
	t_key_flags key_pressed;

	key_pressed = *key_flag;
	if (key_pressed & WHEEL_UP)
	{
		camera->scaling = camera->scaling * 1.2;
		*key_flag = *key_flag ^ WHEEL_UP;
	}
	if (key_pressed & WHEEL_DOWN)
	{
		camera->scaling = camera->scaling / 1.2;
		*key_flag = *key_flag ^ WHEEL_DOWN;
	}
}

void	set_fractal_type(t_camera *camera, int key)
{
	if (key == 46)
		camera->type = 'M';
	else if (key == 38)
		camera->type = 'J';
	else if (key == 8)
		camera->type = 'C';
}
