/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:35:41 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
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
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*cell1;
// 	t_list	*cell2;
// 	t_list	*cell3;

// 	lst = NULL;
// 	int *content1 = malloc(sizeof(int));
// 	int *content2 = malloc(sizeof(int));
// 	int	*content3 = malloc(sizeof(int));
// 	*content1 = 42;
// 	*content2 = 66;
// 	*content3 = 314;
// 	cell1 = ft_lstnew(content1);
// 	cell2 =	ft_lstnew(content2);
// 	cell3 = ft_lstnew(content3);
// 	ft_lstadd_front(&lst, cell1);
// 	ft_lstprint(lst);
// 	ft_lstadd_front(&lst, cell2);
// 	ft_lstprint(lst);
// 	ft_lstadd_front(&lst, cell3);
// 	ft_lstprint(lst);

// 	while(lst)
// 	{
// 		t_list *tmp = lst;
// 		lst = lst->next;
// 		free(tmp->content);
// 		free(tmp);
// 	}
// 	return (0);
// }