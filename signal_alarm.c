/**
 * File: 
 * Modified by:
 * 
 * Brief summary of program:
 */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void handle_signal(int signo) {
    if(signo == SIGALRM){
        printf("Got the signal alarm\n");
    }
    // pid_t pid = getpid();
    // kill(pid, SIGKILL);
    exit(0);
}

int main (int argc, char* argv[]) {
    //assign the signal
    signal(SIGALRM, handle_signal);

    // wait 5 seconds
    alarm(5);
    // Starting wait
    printf("Starting wait\n");
    for(int i = 1; i < 10; i ++){
        sleep(1);
        printf("%d\n", i);
    }

    // Return to exit the program
    return 0;
}