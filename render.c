/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:46:36 by leo               #+#    #+#             */
/*   Updated: 2026/01/29 19:33:25 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_pixel(t_fractol *f, int x, int y, int color)
{
    char    *dst;

    dst = f->addr + (y * f->line_len + x * (f->bpp / 8));
    *(unsigned int *)dst = color;
}

void    render(t_fractol *f)
{
    int     x;
    int     y;
    int     iter;
    double  c_re;
    double  c_im;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            c_re = f->min_re + x * (f->max_re - f->min_re) / WIDTH;
            c_im = f->max_im - y *(f->max_im - f->min_im) / HEIGHT;
            iter = mandelbrot(c_re, c_im, f->max_iter);
            put_pixel(f, x, y, get_color(iter, f->max_iter));
            x++;
        }
        y++;
    }
    
}

