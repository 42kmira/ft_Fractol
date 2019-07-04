/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:54 by kmira             #+#    #+#             */
/*   Updated: 2019/07/03 22:44:22 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_application(void **params)
{
	t_app	*app;
	t_key_flags	*dispatch_table;

	app = params[APPLICATION];
	dispatch_table = params[KEY_DISPATCH_TABLE];
	free(dispatch_table);
	mlx_destroy_image(app->mlx_connection, app->window);
	system("leaks fractol");
	sleep(1);
	EXIT(GREEN"Program closed successfully");
}
