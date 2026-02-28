/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 18:39:01 by leo               #+#    #+#             */
/*   Updated: 2026/02/28 20:56:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mandelbrot(t_complex c)
{
    t_complex   z;
    int     i;

    z.real = 0;
    z.imaginary = 0;
    i = 0;

    while (i < MAX_ITER && get_module(z) < 4)
    {
        z = add_complex(pow_complex(z), c);
        i++;
    }
    return (i);
}