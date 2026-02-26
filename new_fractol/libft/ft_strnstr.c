/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:17:58 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/01 17:45:21 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (big == NULL && little == NULL)
		return (NULL);
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && ft_strlen(big) != 0)
	{
		if (len - i < ft_strlen(little))
			return (NULL);
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			j++;
			if (j == ft_strlen(little))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char *big = "Foo Bar Baz";
	const char *little = "Bar";
	ft_strnstr(big, little, 5);
	printf("%s\n", ft_strnstr(big, little, 5));
	printf("%p", ft_strnstr(big, little, 5));
	return 0;

}*/
