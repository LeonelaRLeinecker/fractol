/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 20:19:39 by leo               #+#    #+#             */
/*   Updated: 2026/03/03 09:42:22 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter)
{
	int		r;
	int		g;
	int		b;
	double	t;

	if (iter == MAX_ITER)
		return (0x000000FF);
	t = (double)iter / (double)MAX_ITER;
	r = (int)(pow(sin(0.3 * M_PI + t * 5.0 * M_PI), 2.0) * 255);
	g = (int)(pow(sin(0.3 * M_PI + t * 5.0 * M_PI + 2.0), 2.0) * 255);
	b = (int)(pow(sin(0.3 * M_PI + t * 5.0 * M_PI + 4.0), 2.0) * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 0x000000FF);
}

