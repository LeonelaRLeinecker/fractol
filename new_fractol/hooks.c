/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:42:42 by leo               #+#    #+#             */
/*   Updated: 2026/03/03 10:08:01 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keyboard_event(void *param)
{
	t_config	*config;
	mlx_t		*mlx;
	int			flag;

	flag = 0;
	config = param;
	mlx = config->mlx;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		move(config, -0.1, 0);
		flag = 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		move(config, 0.1, 0);
		flag = 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		move(config, 0, -0.1);
		flag = 1;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		move(config, 0, 0.1);
		flag = 1;
	}
	if (flag)
	render (config);
}

void	zoom(t_config *config, double zoom_f, int m_x, int m_y)
{
	t_complex	m;

	m = pixel_to_complex(m_x, m_y, config);
	config->x_range.start = m.real + (config->x_range.start - m.real) *	zoom_f;
	config->x_range.end = m.real + (config->x_range.end - m.real) * zoom_f;
	config->y_range.start = m.imaginary + (config->y_range.start - m.imaginary) * zoom_f;
	config->y_range.end = m.imaginary + (config->y_range.end - m.imaginary) * zoom_f;
}

void	scroll_event(double xdelta, double ydelta, void* param)
{
	t_config	*config;
	int			m_x;
	int			m_y;

	(void)xdelta;
	config = param;
	mlx_get_mouse_pos(config->mlx, &m_x, &m_y);
	if (ydelta < 0) 
	{
		zoom(config, 0.8, m_x, m_y);
		render(config);
	}
	if (ydelta > 0) 
	{
		zoom(config, 1.2, m_x, m_y);
		render(config);
	}
}

void	move(t_config *config, double vertical, double horizontal)
{
	double	x_magnitude;
	double	y_magnitude;

	x_magnitude = config->x_range.end - config->x_range.start;
	y_magnitude = config->y_range.end - config->y_range.start;
	config->x_range.start += x_magnitude * horizontal;
	config->x_range.end += x_magnitude * horizontal;

	config->y_range.start += y_magnitude * vertical;
	config->y_range.end += y_magnitude * vertical;
}
