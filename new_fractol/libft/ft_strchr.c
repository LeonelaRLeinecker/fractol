/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:59:28 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/30 13:50:58 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*aux;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			aux = (char *)&s[i];
			return (aux);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		aux = (char *)&s[i];
		return (aux);
	}
	else
		return (NULL);
}
/*
int	main()
{
	const char	s[] = "hola";
	printf("%s", ft_strchr(s, 2));
	return 0;	
}*/
