#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>


//
int pipeFD[2];

void handle() {
    char str[32];
    strcpy(str, "O2IXLB\0");
    write(pipeFD[1], str, strlen(str));
}

int main() {
    pid_t cpid;
    char buffer[1024];
    int rek;

    if (pipe(pipeFD) == -1) {
        perror("pipe");
        exit(-1);
    }

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(-1);
    }

    if (cpid == 0) { // gyerek  
        printf("%d: I'm a child\n", getpid());

        close(pipeFD[0]);

        signal(SIGALRM, (void (*)()) handle);
        pause();
        close(pipeFD[1]);

    } else { // szulo  
        printf("%d: I'm a parent\n", getpid());
        wait(NULL);
        close(pipeFD[1]);
        while(read(pipeFD[0], &buffer, 1) > 0) {
            printf("%c", buffer);
        }
        //printf("\n%d: Le lett zarva a cso masik oldala.\n", getpid());
        close(pipeFD[0]);
    }
    return 0;
}