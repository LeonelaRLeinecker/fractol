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

void render(t_config *config) {
    
    int		x;
	int		y;
	int 	iter;
	
	t_complex z;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z = pixel_to_complex(x, y, config);
			iter = mandelbrot(z);
			mlx_put_pixel(config->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
		
	mlx_image_to_window(config->mlx, config->img, 0, 0);
    
}

