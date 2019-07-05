/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_application.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:01 by kmira             #+#    #+#             */
/*   Updated: 2019/07/04 20:01:38 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_move(int x, int y, void **params)
{
	t_camera	*camera;
	t_key_flags	*keys_pressed;

	camera = params[CAMERA];
	keys_pressed = params[KEYS_PRESSED];
	if (!(FREEZE & *keys_pressed))
	{
		camera->real_constant = x / (float)WINDOW_HEIGHT;
		camera->imaginary_constant = y / (float)WINDOW_WIDTH;
	}
	return (1);
}

int		mouse_pressed(int key, int x, int y, void **params)
{
	t_key_flags	*keys_pressed;

	keys_pressed = params[KEYS_PRESSED];
	if (key == 4)
		*keys_pressed = *keys_pressed | WHEEL_UP;
	if (key == 5)
		*keys_pressed = *keys_pressed | WHEEL_DOWN;
	(void)x;
	(void)y;
	return (1);
}

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
	set_fractal_type((t_camera *)(params[CAMERA]), key);
	if (key == 43)
		((t_camera *)params[CAMERA])->color_type += 1;
	if (((t_camera *)params[CAMERA])->color_type == 4)
		((t_camera *)params[CAMERA])->color_type = 1;
	if (key == 3)
		*pressed_keys = *pressed_keys ^ FREEZE;
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
