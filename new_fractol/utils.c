/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:35:48 by leo               #+#    #+#             */
/*   Updated: 2026/02/28 20:33:23 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_complex   add_complex(t_complex a, t_complex b)
{
    t_complex res;

    res.real =  a.real + b.real;
    res.imaginary = a.imaginary + b.imaginary;
    return (res);
}

double   get_module(t_complex a)
{
    return ((a.real * a.real) + (a.imaginary * a.imaginary));
}

t_complex   pow_complex(t_complex z)
{
    t_complex res;
    
    res.real = (z.real * z.real) - (z.imaginary * z.imaginary);
    res.imaginary = 2 * z.real * z.imaginary;
    return (res);
}