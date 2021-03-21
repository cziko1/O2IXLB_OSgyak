#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 255

#define FALSE 0
#define TRUE 1

int main()
{

	char str[SIZE];
    int start = 1;

	while(start) {
        scanf("%s", str);
        if (str[0] == 'n') {
            start = 0;
        } else {
            system(str);
            printf("Would you like to continue ? N => Nope\n If you would like to continue DON'T PRESS THE Y button\nOnly enter the next command\n");
        }
	}
	exit(0);
}