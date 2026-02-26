/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:19:02 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/08 17:07:56 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *list)
{
	int	i;

	i = 0;
	if (! list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
/*int	main()
{
	t_list	*nodo1;
	t_list	*nodo2;
	char	*str;
	char	*str1;

	str = "hola, mundo!";
	str1 = "cruel";

	nodo1 = ft_lstnew(str);
	nodo2 = ft_lstnew(str1);

	nodo1->next = nodo2;
	nodo2->next = NULL;

	printf("esta es mi lista de nodos %d", ft_lstsize(nodo1));
	return 0;

}*/