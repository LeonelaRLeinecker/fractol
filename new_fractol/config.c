/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:32:47 by leo               #+#    #+#             */
/*   Updated: 2026/03/01 20:36:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void print_help(void) {
    ft_putstr_fd("Invalid arguments. You need to choose fractal type.\n Available options:\n\tmandelbrot\n\tjulia\n", 1);
    ft_putstr_fd("For julia set, also provide the value for c. Real and imaginary parts. Example ./fractol julia -0.70176 -0.50\n", 1);
    exit(0);
}

t_complex get_julia_center(int argc, char **argv) {
    t_complex c;
    
    if (argc < 4) {
	   c.real = -0.70176;
	   c.imaginary = -0.3842;
    } else {
        c.real = atod(argv[2]);
        c.imaginary = atod(argv[3]);
    }

    return c;
}

char *get_fractal_type(int argc, char **argv) {
    if (argc < 2) {
        print_help();
    }

    char *fractal_type = argv[1];
    
    if(ft_strcmp(fractal_type, MANDELBROT) == 0) {
        return MANDELBROT;
    } else if(ft_strcmp(fractal_type, JULIA) == 0) {
        return JULIA;
    }

    print_help();
    return NULL;
}

t_config    create_config(int argc, char **argv)
{
    mlx_t   *mlx;
	t_config    config;
    mlx_image_t *img;
    t_range x_range;
    t_range y_range;
	
    mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	x_range.start = -2;
	x_range.end = 2;
    y_range.start = -2;
	y_range.end = 2;
	config.x_range = x_range;
	config.y_range = y_range;
	config.mlx = mlx;
    config.fractal_type = get_fractal_type(argc, argv);
    config.julia_center = get_julia_center(argc, argv);
    img = mlx_new_image(mlx, WIDTH, HEIGHT);

    if (!img) exit(EXIT_FAILURE);
    config.img = img;

    return config;
}

