/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:47:45 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstres;
	t_list	*cell;

	lstres = NULL;
	while (lst != NULL)
	{
		cell = ft_lstnew(f(lst->content));
		if (!cell)
		{
			ft_lstclear(&lstres, del);
			return (NULL);
		}
		ft_lstadd_back(&lstres, cell);
		lst = lst->next;
	}
	return (lstres);
}

// void	*addOne(void *content)
// {
// 	*(int *)content += 1;
// 	return ((void*)content);
// }

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
// 	t_list *lst = NULL;
// 	int *content1 = malloc(sizeof(int));
// 	int *content2 = malloc(sizeof(int));
// 	*content1 = 69;
// 	*content2 = 42;
// 	t_list *cell1 = ft_lstnew(content1);
// 	t_list *cell2 = ft_lstnew(content2);
// 	ft_lstadd_front(&lst, cell1);
// 	ft_lstadd_front(&lst, cell2);
// 	ft_lstprint(lst);
// 	write(1, "\n", 1);
// 	t_list *lst2 = ft_lstmap(lst, addOne, free);
// 	ft_lstprint(lst2);
// 	return (0);
// }