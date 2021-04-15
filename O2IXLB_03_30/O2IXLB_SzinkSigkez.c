#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void action();

int main() {
    pid_t pid;
    int i;
    
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(-1);
    }
    
    signal(SIGUSR1, action);            // Szülő és a gyerek signal 

    if (pid > 0) {                      // Szülő 
        printf("Sleep 10 sec\n");
        sleep(10);
        kill(pid, SIGUSR1);                 // signal gyerek 

        pause();                            // gyerekre vár
        printf("All done\n");

    } else {                            // gyerek 
        pause();                            //szülőre vár
        printf("Sleep 2 sec\n");
        sleep(2);
        signal(SIGUSR1, SIG_IGN);
        kill(getppid(), SIGUSR1);           // signal szülő 
    }
}

void action() {
    sleep(1);
    printf("Switching\n");
}