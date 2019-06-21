/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 11:41:56 by kmira             #+#    #+#             */
/*   Updated: 2019/06/21 11:48:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_pixel_loc(t_pixel *pixel, int changed)
{
	if (changed)
		printf("NEW PIXEL: (%d, %d)\n", pixel->real_value, pixel->imaginary_value);
	else
		printf("PIXEL:     (%d, %d)\n", pixel->real_value, pixel->imaginary_value);
}
