/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 19:25:18 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/07 10:58:06 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sep_count(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 1;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag != 0)
		{
			flag = 0;
			count++;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

static int	ft_word_size(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**create_memory(char const *s, int size)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)ft_calloc(sizeof(char *), size + 1);
	if (!result)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

static char	**free_split_mem(char **result)
{
	int	i;

	i = 0;
	if (!result)
		return (NULL);
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	int		f_copied;
	int		string_size;
	int		sep;
	char	**result;

	start = 0;
	f_copied = (-1);
	sep = ft_sep_count(s, c);
	result = create_memory(s, sep);
	if (!result)
		return (free_split_mem(result));
	while (++f_copied < sep)
	{
		while (s[start] == c)
			start++;
		string_size = ft_word_size(&s[start], c);
		result[f_copied] = ft_substr(s, (unsigned int)start, string_size);
		if (!result[f_copied])
			return (free_split_mem(result));
		start += string_size;
	}
	return (result);
}

// int	main()
// {
// 	char	s[] = "     ho la como es     tas";
// 	char	c= ' ';
// 	s = ft_split()
// 	int	i = 0;
// 	while (s[i])
// 	{
// 		printf("este es el count word %d\n", s[i]);
// 		i++;
// 	}
// 	// printf("esta es la funcion %s", ft_split(s, c));
// 	return 0;

// }

// int main()
// {
//     // Probar ft_split con una cadena de ejemplo y un delimitador
//     char **result;
//     char str[] = ",hola,,,,,,,,,co,mo,,,,,,,estas,amigo,,,,,,,";
//     char sep = ',';

//     result = ft_split(str, sep);

//     // Imprimir los fragmentos resultantes
//     if (result != NULL)
//     {
//         int i = 0;
//         while (result[i] != NULL)
//         {
//             printf("Fragmento %d: %s\n", i, result[i]);
//             free(result[i]);  // Liberar cada fragmento
//             i++;
//         }
//         free(result);  // Liberar el arreglo de cadenas
//     }

//     return 0;
// }