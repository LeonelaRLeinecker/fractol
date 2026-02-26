/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 16:12:10 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/01 17:11:11 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*aux;

	aux = malloc(nmemb * size);
	if (!aux)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (aux);
	ft_bzero(aux, nmemb * size);
	return (aux);
}
