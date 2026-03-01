/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:29:49 by leo               #+#    #+#             */
/*   Updated: 2026/03/01 19:35:55 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 300
# define HEIGHT 300
# define MAX_ITER 100
# define MANDELBROT "mandelbrot"
# define JULIA "julia"

// Complex
typedef struct t_complex
{
	double  real;
	double  imaginary;
} t_complex;

t_complex   add_complex(t_complex a, t_complex b);
double   get_module(t_complex a);
t_complex   pow_complex(t_complex z);

// Fractal
int mandelbrot(t_complex c);
int julia(t_complex z, t_complex c);

// Config
typedef struct t_range {
	double start;
	double end;
} t_range;

typedef struct t_config {
	mlx_t *mlx;
	mlx_image_t *img;
	t_range x_range;
	t_range y_range;
	char *fractal_type;
	t_complex julia_center;
	
} t_config;

t_config create_config();
void move(t_config *config, double vertical, double horizontal);
void zoom(t_config *config, double factor);
void print_help(void);

// Render
void render(t_config *config);

// Hooks
void keyboard_event(void* param);
void scroll_event(double xdelta, double ydelta, void* param);

// Parse
double atod(char *s);

#endif
