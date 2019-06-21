/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:20:15 by kmira             #+#    #+#             */
/*   Updated: 2019/06/20 22:09:13 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include "debug.h"

# include "../minilibx_macos/mlx.h"

# include "fractol_structs.h"
# include "../libft/libft.h"

# include <stdlib.h>
# include <string.h>

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MARCOS
*/

# define WINDOW_HEIGHT 255
# define WINDOW_WIDTH 255
# define WINDOW_NAME "Fractol"

# define BYTES_PER_PIXEL 4

# ifndef EXIT
#  define EXIT (error_msg) ft_puterror(error_msg)
# endif

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: application.c
*/

t_app	create_application(void);


/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: initialization.c
** Preperation step for Fractol
*/

t_pixel	**create_pixel_array(void);

#endif
