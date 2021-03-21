#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	int status;

	if ((pid = fork()) < 0) 
		perror("fork hiba");
	else if (pid == 0)
		exit(7);

	if (wait(&status) != pid)
		perror("wait hiba");

	if (WIFEXITED(status))
		printf("Normal finishing, Value = %d\n", WEXITSTATUS(status));


	if ((pid = fork()) < 0) 
		perror("fork error");
	else if (pid == 0)
		abort();
	
	if (wait(&status) != pid)
		perror("wait error");
	
	if (WIFSIGNALED(status))
		printf("abnormal finishing, singal number = %d\n", WTERMSIG(status));
	
	/* ERROR */
	/*
	if ((pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0)
		a = 4/0;
	if (wait(&status) != pid)
		perror("wait error");
	
	if (WIFSIGNALED(status))
		printf("%d", WTERMSIG(status));	
	*/
	exit(0);
}