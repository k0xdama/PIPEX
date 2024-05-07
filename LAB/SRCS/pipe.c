# include "../INCLUDES/test_pipex.h"

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    pid_t	pid;
	char **cmd;
	
	(void)argc;
	(void)argv;
	cmd = ft_split("ping -c 5 google.fr", ' ');
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