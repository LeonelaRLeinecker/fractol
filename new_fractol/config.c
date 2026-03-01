/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:32:47 by leo               #+#    #+#             */
/*   Updated: 2026/03/01 19:44:32 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void print_help(void) {
    printf("Invalid arguments. You need to choose fractal type.\n Available options:\n\tmandelbrot\n\tjulia\n");
    printf("For julia set, also provide the value for c. Real and imaginary parts. Example ./fractol julia -0.70176 -0.50\n");
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

void move(t_config *config, double vertical, double horizontal) {
    double x_magnitude = config->x_range.end - config->x_range.start;
    double y_magnitude = config->y_range.end - config->y_range.start;

    config->x_range.start += x_magnitude * horizontal;
    config->x_range.end += x_magnitude * horizontal;

    config->y_range.start += y_magnitude * vertical;
    config->y_range.end += y_magnitude * vertical;
}

void zoom(t_config *config, double zoom_factor)
{
    double x_center;
    double y_center;
    double x_width;
    double y_height;

    x_center = (config->x_range.start + config->x_range.end) / 2.0;
    y_center = (config->y_range.start + config->y_range.end) / 2.0;

    x_width = (config->x_range.end - config->x_range.start) * zoom_factor;
    y_height = (config->y_range.end - config->y_range.start) * zoom_factor;

    config->x_range.start = x_center - x_width / 2.0;
    config->x_range.end = x_center + x_width / 2.0;

    config->y_range.start = y_center - y_height / 2.0;
    config->y_range.end = y_center + y_height / 2.0;
}