/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:22:06 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/30 17:14:26 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	result;

	i = 0;
	result = ft_strlen(src);
	if (size == 0)
		return (result);
	while (i < (size -1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (result);
}
/*
int main()
{
	char	dest[] = "hola";
	const char	src[] = "mu";
	ft_strlcpy(dest, src, 5);
	printf("%s\n", dest);
	printf("%zu\n", ft_strlcpy(dest, src, 2));
	return 0;
}*/
