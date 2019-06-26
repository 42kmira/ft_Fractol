/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:20:15 by kmira             #+#    #+#             */
/*   Updated: 2019/06/26 02:45:16 by kmira            ###   ########.fr       */
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

# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# include "debug.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MARCOS
*/

# define WINDOW_HEIGHT 500
# define WINDOW_WIDTH 500
# define WINDOW_NAME "Fractol"

# define BYTES_PER_PIXEL 4

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

# define APPLICATION 0
# define CAMERA 1
# define PIXEL_ARRAY 2
# define KEY_DISPATCH_TABLE 3
# define KEYS_PRESSED 4

# define DELTA_TRANSLATE 10
# define DELTA_SCALING 1
# define ZOOM_STEPS 10

# define DEBUG 0

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: application.c
*/

t_app	create_application(void);
void	application_loop(t_app *app, t_camera *camera, t_pixel **pixel_array);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_application.c
** Handles user input (e.g Keyboard, Mouse)whilst the program is running.
*/

int		switch_key_flag_on(int key, void **params);
int		switch_key_flag_off(int key, void **params);
void	set_translate(t_key_flags *key_flags, t_camera *camera);
void	set_zoom(t_key_flags *key_flag, t_camera *camera);

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
int		render(void **params);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: camera.c
** Functions having to do with the t_camera structure.
*/

t_camera	create_camera(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: exit_application.c
** Functions having to do with the t_camera structure.
*/

void	close_application(void **params);

#endif
