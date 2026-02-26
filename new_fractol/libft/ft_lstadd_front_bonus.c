/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:53:27 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/07 21:56:35 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (!list || !new)
	{
		return ;
	}
	new ->next = *list;
	*list = new;
}

/*int	main(void)
{
	t_list *head = NULL;
	t_list *nodo1 = ft_lstnew("primer nodo");
	t_list *nodo2 = ft_lstnew("segundo nodo");

	// Agregamos nodo1 primero
	ft_lstadd_front(&head, nodo1);
	// Luego agregamos nodo2 al frente
	ft_lstadd_front(&head, nodo2);

	// Recorremos la lista para ver el orden
	t_list *temp = head;
	while (temp)
	{
		printf("Contenido: %s\n", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}*/