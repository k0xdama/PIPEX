/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 05:34:52 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char *str = "oncherchelecparlaouparici";
// 	int c = 'c';
// 	printf("strrchr retourne : %s\n", ft_strrchr(str, c));
// }

// int	main(void)
// {
// 	char s[] = "tripouille";
// 	char s1[] = "";
// 	printf("%s\n", strrchr(s, 't' + 256));
// 	printf("%s\n", ft_strrchr(s, 't' + 256));
// 	printf("%s\n", strrchr(s1, 0));
// 	printf("%s\n", ft_strrchr(s1, 0));
// }