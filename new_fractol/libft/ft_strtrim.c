/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:44:50 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/03 19:00:59 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_initial_trim(char const *str, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (1)
	{
		found = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				found = 1;
				i++;
				break ;
			}
			j++;
		}
		if (!found)
			break ;
	}
	return (i);
}

int	ft_finish_trim(char const *str, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = ft_strlen(str) - 1;
	while (1)
	{
		found = 0;
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				found = 1;
				i--;
				break ;
			}
			j++;
		}
		if (!found)
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	if (!*set)
		len = ft_strlen(s1);
	if (ft_initial_trim(s1, set) > ft_finish_trim(s1, set))
	{
		len = 1;
		trim = (char *)malloc(sizeof(char) * len);
		if (!trim)
			return (NULL);
		trim[0] = '\0';
		return (trim);
	}
	len = (size_t)(ft_finish_trim(s1, set) - ft_initial_trim(s1, set) + 1);
	trim = (char *)malloc(sizeof(char) * len + 1);
	if (!trim)
		return (NULL);
	ft_strlcpy(trim, &s1[ft_initial_trim(s1, set)], len + 1);
	return (trim);
}
/*
int	main()
{
	char	s1[] = "abcoooabc";
	char	set[] = "abc";
	printf("%s\n", ft_strtrim(s1, set));
	printf("%s\n", ft_strtrim("werholraaeerw", "wer"));

	printf("%s\n", ft_strtrim("werho", ""));

	printf("%s\n", ft_strtrim("\t \r \n\n\n", ""));

	return 0;
}*/
