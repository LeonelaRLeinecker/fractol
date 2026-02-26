/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:54:10 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/23 20:11:47 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	char unsigned	*aux;
	size_t			i;

	aux = s;
	i = 0;
	while (i < n)
	{
		aux[i] = '\0';
		i++;
	}
}

/*int	main()
{
	char	str[] = "hola";
	int	i = 0;

	printf("%s\n", str);
	ft_bzero(str, 1);
	while (i < 4)
	{
		printf("%c\n", str[i]);
		i++;
	}
	return 0;
}*/
