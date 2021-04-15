#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FILE "O2IXLB.txt"

int main() {

    int file = open(FILE, O_RDWR);
    char srt[255];

    if (file == -1) {
        printf("Error! Could'nt Open this file: %s!\n", FILE);
        return 1;
    }

    printf("File has been open: %s!\n", FILE);
    
    int rd = read(file, srt, sizeof(srt));
    srt[rd] = '\0';

    printf("Scanned details:\n%s\nAll %i byte.\n", srt, rd);

    lseek(file, 0, SEEK_SET);

    char srt2[] = "This is a TEST! 2021/03/23";
    int wr = write(file, srt2, sizeof(srt2));

    printf("On the file:\n%s\nAll %i byte.\n", srt2, wr);

    close(file);
    return 0;
}