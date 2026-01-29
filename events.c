/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:02:03 by leo               #+#    #+#             */
/*   Updated: 2026/01/29 16:38:24 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mouse_hook(int button, int x, int y, t_fractol *f)
{
    if (button == ZOOM_IN)
        zoom(f, 0.8);
    if (button == ZOOM_OUT)
        zoom(f, 1.2);
    render(f);
    return (0);
}