/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 20:52:03 by lleineck          #+#    #+#             */
/*   Updated: 2026/02/28 17:12:12 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*aux;
	//size_t	len_aux;

	i = 0;
	aux = (char *) s;
	//len_aux = ft_strlen(aux);
	while (i < n)
	{
		if ((unsigned char)aux[i] == (unsigned char)c)
			return ((void *)&aux[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	const char	s[] = "holabb";
	printf("%p\n", ft_memchr(s, 123, 4));
	printf("%s", (char *)ft_memchr(s, 123, 4));
	return 0;

	
}*/
