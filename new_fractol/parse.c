/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:08:35 by leo               #+#    #+#             */
/*   Updated: 2026/03/01 19:34:33 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void skip_spaces(char **s) {
		while (**s && **s < 33) {
		   (*s)++;
		}
}

int get_sign(char **s) {
		int sign;

		sign = 1;

		// si hay un menos, el signo es negativo
		if(**s == '-') {
			sign = -1;
			(*s)++;
		}

		// saltear todo lo otro
		while(**s == '+' || **s == '-') {
				(*s)++;
		}

		return sign;
}

int get_base(char **s) {
		int base = 0;

		while(ft_isdigit(**s)) {
					base = base * 10 + (**s - 48);
					(*s)++;
		}

		return base;
}

double get_frac(char **s) {
		double frac = 0.0;
		int acc = 1;

		while(ft_isdigit(**s)) {
					frac = frac * 10.0 + (**s - 48);
					acc *= 10;
					(*s)++;
		}

		return frac / acc;
}

double atod(char *s) {
		int sign;
		int base;
		double frac;

		skip_spaces(&s);

		sign = get_sign(&s);
		skip_spaces(&s);
		base = get_base(&s);
		
		if(*s == '.')
			s++;

		frac = get_frac(&s);

		return sign * (base + frac);

}


