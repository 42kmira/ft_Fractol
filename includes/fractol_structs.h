/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 17:20:10 by kmira             #+#    #+#             */
/*   Updated: 2019/07/04 20:05:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCTS_H
# define FRACTOL_STRUCTS_H

# define X 0
# define Y 1
# define I 1
# define Z 2

typedef struct		s_color
{
	char			r_channel;
	char			g_channel;
	char			b_channel;
	char			a_channel;
}					t_color;

typedef	struct		s_pixel
{
	long double		real_value;
	long double		imaginary_value;
	long double		pos[2];
	t_color			color;
}					t_pixel;

typedef struct		s_app
{
	void			*mlx_connection;
	void			*window;
	void			*image;
	char			*image_address;

}					t_app;

typedef	struct		s_camera
{
	double			pos[3];
	long double		scaling;
	long double		real_constant;
	long double		imaginary_constant;
	char			type;
	int				color_type;
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

# define ANY_PRESSED 0b101111111110

enum				e_keys
{
	KEY_UP = 0b000000000010,
	KEY_DOWN = 0b000000000100,
	KEY_LEFT = 0b000000001000,
	KEY_RIGHT = 0b000000010000,
	KEY_ZOOM_IN = 0b000000100000,
	KEY_ZOOM_OUT = 0b000001000000,
	KEY_ESC = 0b000010000000,
	WHEEL_UP = 0b000100000000,
	WHEEL_DOWN = 0b001000000000,
	FREEZE = 0b010000000000,
	MANDELBROT_ON = 0b100000000000,
	UNDEFINED_KEY = 0b000000000001
};

#endif
