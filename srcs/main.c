/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:05:56 by kmira             #+#    #+#             */
/*   Updated: 2019/06/20 22:37:47 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_gradient(char *image_address)
{
	size_t	i;
	size_t	j;
	size_t	row;
	size_t	col;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		row = i * (WINDOW_WIDTH * BYTES_PER_PIXEL);
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			col = j * BYTES_PER_PIXEL;
			image_address[row + col + 2] = (unsigned char)(j);
			image_address[row + col + 1] = (unsigned char)(j);
			image_address[row + col + 0] = (unsigned char)(j);
			j++;
		}
		i++;
	}
}

int		main(void)
{
	t_app	app;
	t_pixel	**pixel_array;

	app = create_application();
	pixel_array = create_pixel_array();
	color_gradient(app.image_address);
	mlx_put_image_to_window(app.mlx_connection, app.window, app.image, 0, 0);

	mlx_loop(app.mlx_connection);

	return (0);
}
