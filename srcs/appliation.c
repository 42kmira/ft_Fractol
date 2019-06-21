/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appliation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:41:34 by kmira             #+#    #+#             */
/*   Updated: 2019/06/20 17:45:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_app	create_application(void)
{
	t_app	app;

	app.mlx_connection = mlx_init();
	app.window = mlx_new_window(
		app.mlx_connection,
		WINDOW_WIDTH,
		WINDOW_HIEGHT,
		WINDOW_NAME);
	return (app);
}
