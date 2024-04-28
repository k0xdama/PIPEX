# include "../INCLUDES/test_pipex.h"

int main(void)
{
    int fd[2];
    pid_t	pid;
	char buffer[10];

	if(pipe(fd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if (!pid)
	{
		close(fd[0]);
		write(fd[1], "Regarde !", 10);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]);
		read(fd[0], buffer, 10);
		close(fd[0]);
		printf("Votre enfant d'adresse à vous : \n%s\n", buffer);
		exit(EXIT_SUCCESS);
	}
}