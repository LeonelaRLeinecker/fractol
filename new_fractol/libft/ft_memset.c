/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:55:56 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/22 20:17:19 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t m)
{
	unsigned char	*aux;
	size_t			i;

	aux = s;
	i = 0;
	while (i < m)
	{
		aux[i] = c;
		i++;
	}
	s = (void *)aux;
	return (s);
}
