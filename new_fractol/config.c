#include "fractol.h"

t_config create_config() {
    mlx_t	*mlx;
	t_config config;
    mlx_image_t *img;
	
    
	mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	
	t_range	x_range;
	x_range.start = -2;
	x_range.end = 2;
    
	t_range	y_range;
	y_range.start = -2;
	y_range.end = 2;

	config.x_range = x_range;
	config.y_range = y_range;
	config.mlx = mlx;
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