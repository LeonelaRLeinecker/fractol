/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <lleineck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:44:06 by lleineck          #+#    #+#             */
/*   Updated: 2026/02/27 20:11:01 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

int	main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*img;
	int		x;
	int		y;
	int		color;
	int		index;

	x = 0;
	y = 0;
	mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!mlx)
		return (EXIT_FAILURE);
	if (!img)
		return (EXIT_FAILURE);
	color = 0xFF0000FF;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			index = (y * WIDTH + 4) * 4;
			img->pixels[index + 0] = (color >> 24) & 0xFF;
			img->pixels[index + 1] = (color >> 16) & 0xFF;
			img->pixels[index + 2] = (color >> 8) & 0xFF;
			img->pixels[index + 3] = color & 0xFF;
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		
		y++;
	}
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

