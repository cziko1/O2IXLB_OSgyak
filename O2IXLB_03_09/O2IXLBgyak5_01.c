#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	if ((pid = fork()) < 0)
		perror("error");
	else if (pid == 0) {
		if (execlp("ls", "ls", "-l", (char *)0) < 0)
			perror("error");
	}

	if (waitpid(pid, NULL, 0) < 0)
		perror("error");

	exit(0);
}