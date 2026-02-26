/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:42:16 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/08 18:50:07 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL)
	{
		list = list->next;
	}
	return (list);
}
// int	main()
// {
// 	t_list	*nodo1;
// 	t_list	*nodo2;
// 	char	*str;
// 	char	*str1;

// 	str = "hola, mundo!";
// 	str1 = "cruel";

// 	nodo1 = ft_lstnew(str);
// 	nodo2 = ft_lstnew(str1);

// 	nodo1->next = nodo2;
// 	nodo2->next = NULL;

// 	printf("esta es mi ultimo nodo %p", ft_lstlast(nodo1));
// 	return 0;

// }/*