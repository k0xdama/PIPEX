/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:53:44 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/16 17:13:40 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/test_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char *tmp;
	char *path;
	char *path_bin;
	char *cmd;
	char **cmd_args;

	tmp = NULL;
	path = NULL;
	path_bin = NULL;
	if (argc > 3)
		exit(EXIT_FAILURE);
	cmd = argv[1];
	cmd_args = ft_split(argv[2], ' ');
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) != 0)
			envp++;
		else
		{
			path = *envp;
			// printf("%s\n", path);
			envp++;
		}
	}
	path_bin = ft_strldup(ft_strnstr(path, "/usr/bin", ft_strlen(path)), 8);
	tmp = ft_strjoin(path_bin, "/");
	path_bin = ft_strjoin(tmp, cmd);
	if (access(path_bin, X_OK) == -1)
	{
		perror("access");
		exit(EXIT_FAILURE);
	}
	else
	{
		execve(path_bin, cmd_args, envp);
	}
	// printf("path_bin = %s\n", path_bin);
	return (0);
}