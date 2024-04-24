/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:38:05 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del((lst)->content);
	free(lst);
}

// void	ft_lstprint(t_list *lst)
// {
// 	while(lst)
// 	{
// 		printf("&cell = %p\n", lst);
// 		// % A CHANGER SELON LE TYPE DE DONNEES
// 		printf("content_cell = %d\n", *((int *)lst->content));
// 		printf("&next_cell = %p\n", lst->next);
// 		printf("|\n|\n|\n");
// 		lst = lst->next;
// 	}
// 	printf("&cell = NULL\n");
// 	printf("content_cell = NULL\n");
// 	printf("&next_cell = NULL\n");
// }

// int	main(void)
// {
// 	t_list *lst = ft_lstnew(malloc(1));
// 	ft_lstprint(lst);
// 	ft_lstdelone(lst, free);
// 	ft_lstprint(lst);
// }