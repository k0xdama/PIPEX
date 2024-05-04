/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:48:51 by pmateo            #+#    #+#             */
/*   Updated: 2024/05/04 07:31:11 by pmateo           ###   ########.fr       */
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

# define MALLOC_ERR -1
# define EXEC_ERR -2
# define TRUE 1
# define FALSE 0

typedef struct s_pipex
{
	int	cmd_count;
	int	pipe_count;
	char *infile;
	char *outfile;
	char **cmds;
	int	is_heredoc;
	int **pipe_tab;
	
}	t_pipex;



#endif