/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:13:42 by pmateo            #+#    #+#             */
/*   Updated: 2023/12/20 15:48:28 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/libft.h"

static char	*cpy(char const *src, int start, int end)
{
	int		i;
	size_t	size;
	char	*dest;

	i = 0;
	size = end - start + 1;
	dest = malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (start <= end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	find_start(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i++;
		}
		else
			j++;
	}
	return (i);
}

static int	find_end(const char *s1, const char *set, int start, int lens1)
{
	int	i;
	int	j;

	i = lens1;
	j = 0;
	while (set[j] != '\0' && start < i)
	{
		if (s1[i] == set[j])
		{
			j = 0;
			i--;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = find_start(s1, set);
	end = find_end(s1, set, start, (ft_strlen(s1) - 1));
	return (cpy(s1, start, end));
}

// int	main(void)
// {
// 	char *s1 = "aifh42045eda";
// 	char *set = "abcdefghijk";
// 	char *res = ft_strtrim(s1, set);
// 	printf("ft_strtrim renvoie : %s\n", res);
// 	free(res);
// }
// int	main(void)
// {
// 	char *s = ft_strtrim("", "123");
// 	printf("%s\n", s);
// }