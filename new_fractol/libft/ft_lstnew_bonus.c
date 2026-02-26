/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleineck <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:33:41 by lleineck          #+#    #+#             */
/*   Updated: 2025/05/07 20:14:58 by lleineck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> next = NULL;
	list -> content = content;
	return (list);
}
/*
int main(void)
{
	t_list *node;
	char *str = "Hola, mundo";

	// Crear un nuevo nodo con el contenido "Hola, mundo"
	node = ft_lstnew(str);

	if (!node)
	{
		printf("Error: no se pudo crear el nodo.\n");
		return (1);
	}

	// Imprimir el contenido del nodo
	printf("Contenido del nodo: %s\n", (char *)node->content);

	// Comprobar que el siguiente nodo es NULL
	if (node->next == NULL)
		printf("El siguiente nodo es NULL, como debe ser.\n");
	else
		printf("Error: el siguiente nodo no es NULL.\n");

	// Liberar memoria (solo del nodo, no del contenido si es literal)
	free(node);

	return 0;
}
*/
