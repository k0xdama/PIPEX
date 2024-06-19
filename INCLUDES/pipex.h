/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:48:51 by pmateo            #+#    #+#             */
/*   Updated: 2024/06/19 18:10:34 by pmateo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include "../LIBFT/INCLUDES/libft.h"
# include "../LIBFT/INCLUDES/ft_printf.h"
# include "../LIBFT/INCLUDES/get_next_line_bonus.h"

# define MALLOC_ERROR 2
# define FORK_ERROR 3
# define PIPE_ERROR 4
# define ACCESS_ERROR 5

typedef struct s_pipex
{
	int		cmd_count;
	int		executed_cmd;
	int		pipe_count;
	int		infile;
	int		outfile;
	char	*all_path;
	char	*path_bin;
	char	*path_to_try;
	char	**tab_path;
	char	**cmds;
	int		is_heredoc;
	int		heredoc_fd;
	char	*limiter;
	pid_t	child_pid;
	int		fd[2];
	int		old_read_fd;
}	t_pipex;

void	init_struct(t_pipex *data, int argc);
void	fill_struct(t_pipex *data, int argc, char **argv);
void	go_exec(t_pipex *data, char **envp);
void	go_exec2(t_pipex *data, char **cmd_args, char **envp);
char	*search_bin(t_pipex *data);
char	*check_bin_path(t_pipex *data);
void	handle_heredoc(t_pipex *data);
void	wait_child(t_pipex *data);
size_t	len_to_space(char *str);
void	clean_exit(t_pipex *data, int exit_code);
void	free_child_tab(char **tab);
void	free_parent_tab(t_pipex *data);
void	print_tab(char **tab);

#endif