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


void	render(t_config *config)
{
	int			x;
	int			y;
	int			iter;
	int			is_mandelbrot;
	t_complex	z;

	is_mandelbrot = ft_strcmp(config->fractal_type, MANDELBROT) == 0;

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
	
			if(is_mandelbrot)
				iter = mandelbrot(z);
			else
				iter = julia(z, config->julia_center);

			mlx_put_pixel(config->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
	mlx_image_to_window(config->mlx, config->img, 0, 0);
}
