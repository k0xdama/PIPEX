/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/04/24 18:47:05 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char *infile;
	char **cmd_arg;
	char *cmd;
	int pid;
	int	ret;
	
	if (argc != 3)
		exit(EXIT_FAILURE);
	infile = argv[1];
	cmd_arg = ft_split(argv[2], ' ');
	cmd = ft_strdup(cmd_arg[0]);
	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		ret = execve(cmd, cmd_arg, envp);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

//argv[2] = "ping google.fr"

//cmd = "ping"
//google.fr