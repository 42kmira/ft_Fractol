/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:54 by kmira             #+#    #+#             */
/*   Updated: 2019/06/21 20:35:17 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	close_application(void **params)
{
	t_app	*app;

	app = params[APPLICATION];
	mlx_destroy_image(app->mlx_connection, app->window);
	EXIT(GREEN"Program closed successfully");
}
