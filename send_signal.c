/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        printf("specify PID when running\n");
        return 1;
    }
    pid_t pid;
    sscanf(argv[1], "%d", &pid);
    srand(time(NULL));

    int random = rand() % 10000;

    union sigval sig_data;
    sig_data.sival_int = random;
    printf("Sending SIGUSR1 to PID %d with val of %d\n", pid, random);

    if(sigqueue(pid, SIGUSR1, sig_data) == -1){
        printf("Somehting went wrong\n");
        return 1;
    }

    printf("it worked\n");
    return 0;
}