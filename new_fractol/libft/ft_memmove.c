/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:26:56 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/30 18:12:41 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*aux;
	unsigned char		*s_aux;
	size_t				i;

	aux = (unsigned char *) dest;
	s_aux = (unsigned char *) src;
	i = 0;
	if (aux == NULL && s_aux == NULL)
		return (NULL);
	if (s_aux < aux)
	{
		while (i < n)
		{
			n--;
			aux[n] = s_aux[n];
		}
	}
	else
	{
		aux = ft_memcpy(aux, s_aux, n);
	}
	dest = (void *) aux;
	return (dest);
}
/*
int	main()
{
	char	dest[3] = " 22";
	char	src[4] = "hola";
	printf("%s\n", dest);
	ft_memmove(dest, src, 2);
	printf("%s\n", dest);
	return 0;

}*/
