/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:15:06 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/30 17:58:17 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dest;
	size_t	i;
	size_t	result;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i = 0;
	result = len_src + len_dest;
	if (len_dest >= size)
	{
		return (len_src + size);
	}
	while (src[i] != '\0' && (len_dest + i) < (size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (result);
}
/*
int	main()
{
	char dest[] = "hola";
	const char 	src[] = "mundo";
	ft_strlcat(dest, src, 8);
	printf("%s\n", dest);
	printf("%zu", ft_strlcat(dest, src, 8));
	return 0;

}*/
