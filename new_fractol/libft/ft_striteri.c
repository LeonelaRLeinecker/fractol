/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:17:55 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/07 15:19:31 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int i, char *str))
{
	unsigned int	i;

	i = 0;
	if (! s || ! f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
