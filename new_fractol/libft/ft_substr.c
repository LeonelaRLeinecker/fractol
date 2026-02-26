/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 19:08:20 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/02 14:07:13 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	if (start > len_s)
		len = 0;
	if (len > len_s - start)
		len = len_s - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		ft_memcpy(sub, s + start, len);
		i++;
	}
	sub[len] = '\0';
	return (sub);
}
/*
int	main()
{
	char	s[]= "hola mundo !";
	printf("%s\n", ft_substr(s, 5, 15));
	printf("%p\n", ft_substr(s, 5, 15));
	return 0;
}*/
