/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:59:14 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
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
// 	t_list *lst;
// 	t_list	*cell1;
// 	t_list	*cell2;
// 	t_list	*cell3;
// 	int	*content1 = malloc(sizeof(int));
// 	int	*content2 = malloc(sizeof(int));
// 	int	*content3 = malloc(sizeof(int));
// 	*content1 = 42;
// 	*content2 = 13;
// 	*content3 = 12;
// 	lst = NULL;
// 	cell1 = ft_lstnew(content1);
// 	cell2 = ft_lstnew(content2);
// 	cell3 = ft_lstnew(content3);
// 	ft_lstadd_front(&lst, cell1);
// 	ft_lstadd_front(&lst, cell2);
// 	ft_lstadd_front(&lst, cell3);
// 	ft_lstprint(lst);
// 	printf("la taille de la liste 'lst' est de : %d\n", ft_lstsize(lst));
// 	while(lst)
// 	{
// 		t_list *tmp = lst;
// 		lst = lst->next;
// 		free(tmp->content);
// 		free(tmp);
// 	}
// 	return (0);
// }