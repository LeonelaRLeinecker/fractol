/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:08:39 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/02 16:56:59 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_tot;
	char	*aux;

	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == '\0' || s2[0] == '\0')
		len_tot = 0;
	len_tot = ft_strlen(s1) + ft_strlen(s2);
	aux = (char *)malloc(sizeof(char) * len_tot + 1);
	if (!aux)
		return (NULL);
	ft_strlcpy(aux, s1, ft_strlen(s1) + 1);
	ft_strlcat(aux, s2, len_tot + 1);
	aux [len_tot] = '\0';
	return (aux);
}
/*
int	main()
{
	char	s1[]= "";
	char	s2[] = "";
	printf("%s", ft_strjoin(s1, s2));
	return 0;
}*/
