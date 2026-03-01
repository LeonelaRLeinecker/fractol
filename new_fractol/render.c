#include "fractol.h"


t_complex   pixel_to_complex(int x, int y, t_config *config)
{
	double  x_percent;
	double  y_percent;
	t_complex   res;
	
	x_percent = (x / (double) WIDTH);
	y_percent = (y / (double) HEIGHT);

	res.real = config->x_range.start + (config->x_range.end - config->x_range.start) * x_percent;
	res.imaginary = config->y_range.start + (config->y_range.end - config->y_range.start) * y_percent;

	return res;
}

int get_color(int iter)
{
	if (iter == MAX_ITER)
		return (0x000000FF); // negro
	return ((iter * 255 / MAX_ITER) << 24) | 0x000000FF;
}

void	render(t_config *config)
{
	int			x;
	int			y;
	int			iter;
	t_complex	z;

	y = 0;
	if (config->img)
		mlx_delete_image(config->mlx, config->img);
	config->img = mlx_new_image(config->mlx, WIDTH, HEIGHT);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = pixel_to_complex(x, y, config);
	
			if(ft_strcmp(config->fractal_type, MANDELBROT) == 0)
				iter = mandelbrot(z);
			else if(ft_strcmp(config->fractal_type, JULIA) == 0)
				iter = julia(z, config->julia_center);
			else
				print_help();

			mlx_put_pixel(config->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_image_to_window(config->mlx, config->img, 0, 0);
}
