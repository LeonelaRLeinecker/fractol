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

void scroll_event(double xdelta, double ydelta, void* param) {
	t_config* config = param;
    (void)xdelta;
    if (ydelta < 0) {
        zoom(config, 0.8);
        render(config);
    }
    if (ydelta > 0) {
        zoom(config, 1.2);
        render(config);
    }

        
}