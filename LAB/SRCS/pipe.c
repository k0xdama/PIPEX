# include "../INCLUDES/test_pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];
	int	infile;
	int	outfile;
    pid_t	pid;
	char **cmd;
	char **cmd1;
	
	(void)argc;
	(void)argv;
	cmd = ft_split("cat", ' ');
	cmd1 = ft_split("wc -l", ' ');
	infile = open("input");
	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (!pid)
	{
		execve("/usr/bin/ping", cmd, envp);
	}
	waitpid(pid, NULL, 0);
}