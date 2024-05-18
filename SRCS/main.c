/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:02 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/18 23:20:51 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../INCLUDES/pipex.h"

void	go_fork(t_pipex *data, int argc, char **argv, char **envp)
{
	pid_t	pid;
	int	fd[2];
	
	fill_struct(data, argc, argv, envp);
	while(data->cmd_count || data->pipe_count)
	{
		pid = fork();
		
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	
	if (argc < 5)
	{
		ft_printf("- Too few arguments... -\n");
		exit(EXIT_FAILURE);
	}
	init_struct(&data, argc);
	data.infile = open(argv[1], O_RDONLY);
	if (data.infile == -1 && ft_strncmp(argv[1], "here_doc", 8) != 0)
	{
		ft_printf("- INFILE provided is incorrect or doesn't exist ! -\n");
		exit(EXIT_FAILURE);	
	}
	data.outfile = open(argv[argc - 1], O_CREAT, O_TRUNC, O_WRONLY, 0777);
	if (data.outfile == -1)
	{
		ft_printf("- Error(s) occured when trying to create or modify OUTFILE\n");
		exit(EXIT_FAILURE);
	}
	go_fork(&data, argc, argv, envp);
}
