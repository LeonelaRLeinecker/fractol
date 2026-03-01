#include "fractol.h"

void keyboard_event(void* param)
{
	t_config* config = param;
    mlx_t *mlx = config->mlx;

    int flag;

    flag = 0;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
    {
        move(config, -0.1, 0);
        flag = 1;
    }    
    if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
    {
        move(config, 0.1, 0);
        flag = 1;
    }
    if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
    {
        move(config, 0, -0.1);
        flag = 1;
    }
    if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
    {
        move(config, 0, 0.1);
        flag = 1;
    }
    
    if (flag)
        render(config);
}

void zoom(t_config *config, double zoom_factor, int mouse_x, int mouse_y)
{
    t_complex	mouse;

	mouse = pixel_to_complex(mouse_x, mouse_y, config);

	config->x_range.start = mouse.real + (config->x_range.start - mouse.real) *	zoom_factor;
    config->x_range.end = mouse.real + (config->x_range.end - mouse.real) * zoom_factor;
	config->y_range.start = mouse.imaginary + (config->y_range.start - mouse.imaginary) * zoom_factor;
	config->y_range.end = mouse.imaginary + (config->y_range.end - mouse.imaginary) * zoom_factor;

}

void scroll_event(double xdelta, double ydelta, void* param) 
{
	t_config* config = param;
    int mouse_x;
	int mouse_y;
    
	(void)xdelta;
    mlx_get_mouse_pos(config->mlx, &mouse_x, &mouse_y);
    if (ydelta < 0) 
	{
        zoom(config, 0.8, mouse_x, mouse_y);
        render(config);
    }
    
    if (ydelta > 0) 
	{
        zoom(config, 1.2, mouse_x, mouse_y);
        render(config);
    }    
}

void move(t_config *config, double vertical, double horizontal) {
    double x_magnitude = config->x_range.end - config->x_range.start;
    double y_magnitude = config->y_range.end - config->y_range.start;

    config->x_range.start += x_magnitude * horizontal;
    config->x_range.end += x_magnitude * horizontal;

    config->y_range.start += y_magnitude * vertical;
    config->y_range.end += y_magnitude * vertical;
}
