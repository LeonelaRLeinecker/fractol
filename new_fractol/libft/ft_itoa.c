/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:18:50 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/07 11:33:35 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_count_to_converse(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static char	*create_list_memory(int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	return (str);
}

static void	ft_converse(int n, char *str, int *i)
{
	if (n < 0)
	{
		str[(*i)++] = '-';
		if (n == INT_MIN)
		{
			str[(*i)++] = '2';
			n = 147483648;
		}
		else
			n = -n;
	}
	if (n >= 10)
	{
		ft_converse(n / 10, str, i);
	}
	str[(*i)++] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_count_to_converse(n);
	str = create_list_memory(len + 1);
	if (!str)
		return (NULL);
	ft_converse(n, str, &i);
	str[i] = '\0';
	return (str);
}

// int	main()
// {
// 	printf("%s\n", ft_itoa(97)); // Debería imprimir "97"
//     printf("%s\n", ft_itoa(-42)); // Debería imprimir "-42"
//     printf("%s\n", ft_itoa(0)); // Debería imprimir "0"
// 	printf("%s", ft_itoa(247483648));
// 	return 0;
// }
