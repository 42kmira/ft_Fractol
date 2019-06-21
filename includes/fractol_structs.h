/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:20:10 by kmira             #+#    #+#             */
/*   Updated: 2019/06/20 17:39:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCTS_H
# define FRACTOL_STRUCTS_H

# define X 0
# define Y 1
# define Z 2

typedef	struct		s_pixel
{
	int				iteration;
	int				real_value;
	int				imaginary_value;
}					t_pixel;

typedef struct		s_color
{
	char			r_channel;
	char			g_channel;
	char			b_channel;
	char			a_channel;
}					t_color;

typedef struct		s_app
{
	void			*mlx_connection;
	void			*window;
}					t_app;

typedef	struct		s_camera
{
	int				pos[3];
	int				scaling[3];
	int				constant;
}					t_camera;

typedef int			t_key_flags;

typedef struct		s_keys
{
	int				key;
	t_key_flags		key_flag;
}					t_keys;

typedef struct		s_user_event
{
	t_key_flags		key_pressed;
}					t_event;

enum				e_keys
{
    KEY_UP           = 0b00000000000010,
    KEY_DOWN         = 0b00000000000100,
    KEY_LEFT         = 0b00000000001000,
    KEY_RIGHT        = 0b00000000010000,
    KEY_ROTATE_UP    = 0b00000000100000,
    KEY_ROTATE_DOWN  = 0b00000001000000,
    KEY_ROTATE_LEFT  = 0b00000010000000,
    KEY_ROTATE_RIGHT = 0b00000100000000,
    KEY_INCREASE_ALT = 0b00001000000000,
    KEY_DECREASE_ALT = 0b00010000000000,
    KEY_ZOOM_IN      = 0b00100000000000,
    KEY_ZOOM_OUT     = 0b01000000000000,
    KEY_ESC          = 0b10000000000000,
    UNDEFINED_KEY    = 0b00000000000001
};

#endif
