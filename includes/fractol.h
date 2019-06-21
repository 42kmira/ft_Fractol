/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:20:15 by kmira             #+#    #+#             */
/*   Updated: 2019/06/21 12:32:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/


# include "../minilibx_macos/mlx.h"

# include "fractol_structs.h"
# include "color.h"
# include "libft.h"

# include <stdlib.h>
# include <string.h>
# include <math.h>

# include "debug.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MARCOS
*/

# define WINDOW_HEIGHT 510
# define WINDOW_WIDTH 510
# define WINDOW_NAME "Fractol"

# define BYTES_PER_PIXEL 4

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: application.c
*/

t_app	create_application(void);
void	application_loop(t_app *app, t_pixel **pixel_array, t_camera *camera);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: initialization.c
** Preperation step for Fractol
*/

t_pixel	**create_pixel_array(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: render.c
** Handles the rendering of points and transformations of them
*/

void	transform_points(t_pixel **pixel_arr, t_camera *camera);


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: camera.c
** Functions having to do with the t_camera structure.
*/

t_camera	create_camera(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_application.c
** Handles input of the application.
*/

#endif
