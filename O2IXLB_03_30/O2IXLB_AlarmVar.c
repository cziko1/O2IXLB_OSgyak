#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void do_nothing();

int main () {
	signal(SIGALRM, do_nothing);
	printf("%d How much the waiting time?\n");
	pause();
	printf("Alright! This is my time!\n");
}

void do_nothing(){;}