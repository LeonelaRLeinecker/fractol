/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:14:20 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/30 17:00:35 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*aux;
	unsigned char	*aux_1;
	size_t			i;

	aux = (unsigned char *) dest;
	aux_1 = (unsigned char *) src;
	i = 0;
	if (aux == NULL && aux_1 == NULL)
		return (NULL);
	while (i < n)
	{
		aux[i] = aux_1[i];
		i++;
	}
	dest = (void *) aux;
	return (dest);
}
/*int	main()
{
	char	str[] = "222222";
	char	dest[] = "hola mundo";
	printf("%s\n", dest);
	ft_memcpy(dest, str, 2);
	printf("%s\n", dest);
	return 0;
}*/
