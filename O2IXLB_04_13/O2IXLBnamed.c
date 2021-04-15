#include <stdio.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    pid_t cpid;
    int ret;
    int fd;
    char buffer[32];

    cpid = fork();
    if (cpid == -1) {
        perror("fork()");
        exit(-1);
    }

    if (cpid == 0) { // child
        printf("%d: I'm a child\n", getpid());
        
        fd = open("BRZGJZ", O_RDWR);
        if (fd == -1) {
            perror("open()");
            exit(-1);
        }

        strcpy(buffer, "Cziko TiVadar\0");
        write(fd, buffer, strlen(buffer));

        close(fd);
    } else { // parent
        printf("%d: I'm a parent\n", getpid());

        ret = mkfifo("O2IXLB", 0666);
        if (ret == -1) {
            perror("mkfifo()");
            exit(-1);
        }

        wait(NULL);

        fd = open("O2IXLB", O_RDWR);
        if (fd == -1) {
            perror("open()");
            exit(-1);
        }

        ret = read(fd, buffer, 32);
        printf("read() %d byte, string: %s\n", ret, buffer);

        close(fd);
        unlink("O2IXLB");
    }

    return 0;
}