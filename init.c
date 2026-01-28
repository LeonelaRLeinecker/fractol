/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:40:46 by leo               #+#    #+#             */
/*   Updated: 2026/01/28 20:21:54 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    init_fractol(t_fractol *f, char **argv)
{
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->addr = mlx_get_data_addr(f->img, &f->bpp, &f->line_len, &f->endian);
    f->min_re = -2.0;
    f->max_re = 2.0;
    f->min_im = -2.0;
    f->max_im = 2.0;
    f->max_iter = 100;
    f->fractal_type = MANDELBROT;
}