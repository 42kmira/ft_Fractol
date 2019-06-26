/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:01 by kmira             #+#    #+#             */
/*   Updated: 2019/06/25 20:53:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		switch_key_flag_on(int key, void **params)
{
	size_t		i;
	t_keys		*key_dispatch_table;
	t_key_flags	*pressed_keys;

	i = 0;

	key_dispatch_table = params[KEY_DISPATCH_TABLE];
	pressed_keys = params[KEYS_PRESSED];
	while (key_dispatch_table[i].key != 0)
	{
		if (key_dispatch_table[i].key == key)
			*pressed_keys = *pressed_keys | key_dispatch_table[i].key_flag;
		i++;
	}
	return (1);
}

int		switch_key_flag_off(int key, void **params)
{
	size_t		i;
	t_keys		*key_dispatch_table;
	t_key_flags	*pressed_keys;

	i = 0;
	key_dispatch_table = params[KEY_DISPATCH_TABLE];
	pressed_keys = params[KEYS_PRESSED];
	while (key_dispatch_table[i].key != 0)
	{
		if (key_dispatch_table[i].key == key)
			*pressed_keys = *pressed_keys ^ key_dispatch_table[i].key_flag;
		i++;
	}
	return (1);
}

void	set_translate(t_key_flags *key_flags, t_camera *camera)
{
	t_key_flags key_pressed;

	key_pressed = *key_flags;
	if (key_pressed & KEY_UP)
		camera->pos[X] = camera->pos[X] - DELTA_TRANSLATE;
	if (key_pressed & KEY_DOWN)
		camera->pos[X] = camera->pos[X] + DELTA_TRANSLATE;
	if (key_pressed & KEY_LEFT)
		camera->pos[Y] = camera->pos[Y] + DELTA_TRANSLATE;
	if (key_pressed & KEY_RIGHT)
		camera->pos[Y] = camera->pos[Y] - DELTA_TRANSLATE;
}

void	set_zoom(t_key_flags *key_flag, t_camera *camera)
{
	t_key_flags key_pressed;

	key_pressed = *key_flag;
	if (key_pressed & WHEEL_UP && camera->scaling >= DELTA_SCALING + 1)
	{
		camera->scaling = camera->scaling - DELTA_SCALING;
		*key_flag = *key_flag ^ WHEEL_UP;
	}
	if (key_pressed & WHEEL_DOWN && camera->scaling <= INT_MAX - DELTA_SCALING)
	{
		camera->scaling = camera->scaling + DELTA_SCALING;
		*key_flag = *key_flag ^ WHEEL_DOWN;
	}
}
