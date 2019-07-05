/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:20:15 by kmira             #+#    #+#             */
/*   Updated: 2019/07/04 20:30:42 by kmira            ###   ########.fr       */
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
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MARCOS
*/

# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000
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
# define DELTA_SCALING 50

# define IMG_ADDR 0
# define CAMERA 1
# define SECT 3

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: application_utils.c
** Utility functions involved in the maintaining and running
** of the Fract'Ol application.
*/

t_keys		*get_key_table(void);
void		set_translate(t_key_flags *key_flags, t_camera *camera);
void		set_zoom(t_key_flags *key_flag, t_camera *camera);
void		set_fractal_type(t_camera *camera, int key);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: application.c
*/

t_app		create_application(void);
void		application_loop(t_app *app, t_camera *camera, t_pixel **pixel_arr);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: color_pallete.c
** Decides which color pallete to use and sets the appropriate RGB vaues
** to the image_address based on 'color' functionss.
*/

void		set_color(char *image_addr, size_t i, char iter, t_camera *camera);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: color_pixel.c
** Main algorithm for deciding what to color each pixel.
** Decides the iteration value for each pixel.
*/

int			fractal_function
		(long double real_value, long double imaginary_value, t_camera *camera);
void		*color_pixel(void *param);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: exit_application.c
** Clean up of appliation when closed.
*/

void		close_application(void **params);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: initialization.c
** Preperation step for Fractol
*/

t_camera	create_camera(void);
t_pixel		**create_pixel_array(void);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: input_application.c
** Changes values when a user event (Keyboard, mouse) is registered.
** These values are stored in the camera class (holds user's view state).
*/

int			mouse_move(int x, int y, void **params);
int			mouse_pressed(int key, int x, int y, void **params);
int			switch_key_flag_on(int key, void **params);
int			switch_key_flag_off(int key, void **params);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: render.c
** Handles the rendering of points and transformations of them
*/

void		transform_points(t_pixel **pixel_arr, t_camera *camera);
int			render(void **params);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: transform.c
** Functions having to do with the t_camera structure.
*/

void		translate_point(t_pixel *pixel_point, t_camera *camera);
void		transform_points(t_pixel **pixel_array, t_camera *camera);
void		scale_point(t_pixel *pixel_point, t_camera *cam, t_pixel *midpoint);

#endif
