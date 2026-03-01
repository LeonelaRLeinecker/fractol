/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:44:06 by lleineck          #+#    #+#             */
/*   Updated: 2026/03/01 19:41:46 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_config config = create_config(argc, argv);
	
	if (!config.mlx)
		return (EXIT_FAILURE);
	mlx_loop_hook(config.mlx, keyboard_event, &config);
	mlx_scroll_hook(config.mlx, scroll_event, &config);
	render(&config);
	mlx_loop(config.mlx);
	mlx_terminate(config.mlx);
	
	return (EXIT_SUCCESS);
}

