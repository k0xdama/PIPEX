/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:04:05 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
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
// 	t_list	*lst = NULL;
// 	t_list	*cell1;
// 	t_list	*cell2;
// 	t_list	*cell3;
// 	t_list	*cell4;
// 	int	*content1 = malloc(sizeof(int));
// 	int	*content2 = malloc(sizeof(int));
// 	int	*content3 = malloc(sizeof(int));
// 	int	*content4 = malloc(sizeof(int));
// 	*content1 = 1;
// 	*content2 = 2;
// 	*content3 = 3;
// 	*content4 = 4;
// 	cell1 = ft_lstnew(content1);
// 	cell2 = ft_lstnew(content2);
// 	cell3 = ft_lstnew(content3);
// 	cell4 = ft_lstnew(content4);
// 	ft_lstadd_back(&lst, cell1);
// 	ft_lstadd_back(&lst, cell2);
// 	ft_lstadd_back(&lst, cell3);
// 	ft_lstadd_back(&lst, cell4);
// 	ft_lstprint(lst);
// 	return (0);
// }

// int	main(void)
// {
// 	t_list * l = NULL;
// 	t_list *l2 = NULL;
// 	ft_lstadd_back(&l, ft_lstnew((void*)1));
// 	ft_lstadd_back(&l, ft_lstnew((void*)2));
// 	ft_lstadd_back(&l2, ft_lstnew((void*)3));
// 	ft_lstadd_back(&l2, ft_lstnew((void*)4));
// 	ft_lstadd_back(&l, l2);
// 	ft_lstprint(l);
// }