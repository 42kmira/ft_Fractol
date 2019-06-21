/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 20:03:41 by kmira             #+#    #+#             */
/*   Updated: 2019/06/20 20:37:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(t_color color)
{
	int color_value;

	color_value = 0;
	color_value = color_value | (color.a_channel << 16);
	color_value = color_value | (color.r_channel << 16);
	color_value = color_value | (color.b_channel << 8);
	color_value = color_value | (color.g_channel << 0);
	return (color_value);
}
