#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


int main(int argN, char **argS) {
    if (argN < 2) { // Azert ha nem jo a bemenet
        printf("Use:\n\t./neptunkod_gyak9_3.out [PID]\n");
        return 1;
    }

    pid_t cpid = (pid_t) atoi(argS[1]); // bemeneti string-ből -> pid_t tipus konverzio
    kill(cpid, SIGALRM);

    return 0;
}