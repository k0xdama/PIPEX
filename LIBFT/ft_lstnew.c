/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:38:29 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list));
	if (!cell)
		return (NULL);
	cell->content = content;
	cell->next = NULL;
	return (cell);
}

// int	main(void)
// {
// 	t_list	*new_cell;
// 	char *str = "Contenu de la nouvelle cellule";
// 	new_cell = ft_lstnew((void *)str);
// 	if(new_cell != NULL)
// 	{
// 		printf("Content new_cell = %s\n", (char *)new_cell->content);
// 		printf("next_cell of new_cell = %p\n", new_cell->next);
// 	}
// 	else
// 		printf("La création de la nouvelle cellule à échoué.\n");
// 	free(new_cell);
// 	return (0);
// }