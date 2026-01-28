/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:27:57 by leo               #+#    #+#             */
/*   Updated: 2026/01/28 20:06:46 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 600

# define MANDELBROT 1
# define JULIA 2

typedef struct s_fractol
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;                                 
    double  min_re;
    double  max_re;
    double  min_im;
    double  max_im;
    int     max_iter;
    int     fractal_type;
}   t_fractol;

int     mandelbrot(double c_re, double c_im, int max_iter);
int     get_color(int iter, int max_iter);
void    render(t_fractol *f);
#endif