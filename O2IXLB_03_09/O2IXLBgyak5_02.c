#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int status;

	if ((status = system("date")) < 0)
		perror("system() error");

	if (WIFEXITED(status))
		printf("Normal finishing | Value = %d\n", WEXITSTATUS(status));

	if ((status = system("kismalac")) < 0)
		perror("system() error");

	if (WIFEXITED(status))
		printf("Normal finishing | Value = %d\n", WEXITSTATUS(status));

	exit(0);
}