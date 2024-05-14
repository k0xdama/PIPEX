/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:53:44 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/14 16:00:02 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/test_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	while (*envp)
	{
		printf("%s\n", *envp);
		envp++;
	}
	return (0);
}