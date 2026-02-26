/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:36:42 by lleineck          #+#    #+#             */
/*   Updated: 2025/04/30 16:44:40 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_tolower(2));
	printf("%d\n", ft_tolower(65));
	printf("%d\n", ft_tolower(122));
	return 0;
}*/
