/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:10:38 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/07 13:12:57 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	*to_up(unsigned int i, char c)
{
//	char *str;

	while(str[i])
	{
		if (str[i] == c)
		{
			str[i] += 2;
		}
		i++;
	}
	return (str);
}*/
char	*ft_strmapi(char const *str, char (*f)(unsigned int i, char c))
{
	unsigned int	i;
	char			*aux;

	if (!str || !f)
		return (NULL);
	i = 0;
	aux = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!aux)
		return (NULL);
	while (str[i])
	{
		aux[i] = f(i, str[i]);
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
/*int	main()
{
	printf("esta es la cadena original %s\n", "Hola MuNdo");
	printf("esta e sla cadena0 modificada %s", ft_strmapi("Hola MuNdo", to_up);
	return 0;
}*/