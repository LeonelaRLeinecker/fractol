/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:40:46 by leo               #+#    #+#             */
/*   Updated: 2026/01/28 20:10:48 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(double c_re, double c_im, int max_iter)
{
    double  z_re;
    double  z_im;
    double  tmp;
    int     iter;

    z_re = 0.0;
    z_im = 0.0;
    iter = 0;
    while ((z_re * z_re + z_im * z_im) <= 4.0 && iter < max_iter)
    {
        tmp = (z_re * z_re) - (z_im * z_im) + c_re;
        z_im = (2.0 * z_re * z_im) + c_im;
        z_re = tmp;
        iter++;
    }
    return (iter);
}