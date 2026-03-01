/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:19:39 by leo               #+#    #+#             */
/*   Updated: 2026/03/01 21:49:27 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_color(int iter)
{
    double t;
    int R;
    int G;
    int B;

    if (iter == MAX_ITER)
        return 0x000000FF; // negro
    t = (double)iter / (double)MAX_ITER;
    R = (int)(pow(sin(0.3 * M_PI + t * 5.0 * M_PI), 2.0) * 255);
    G = (int)(pow(sin(0.3 * M_PI + t * 5.0 * M_PI + 2.0), 2.0) * 255);
    B = (int)(pow(sin(0.3 * M_PI + t * 5.0 * M_PI + 4.0), 2.0) * 255);
    return ((R << 24) | (G << 16) | (B << 8) | 0x000000FF);
}
