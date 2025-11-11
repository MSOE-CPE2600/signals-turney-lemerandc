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

void User_signal(int signo, siginfo_t *info, void *context) {
    if(info == NULL){
        printf("No info recieved\n");
    } else {
        printf("Recieved SIGUSR1 with sival_int: %d\n", info->si_value.sival_int);
    }
}

int main(int argc, char* argv[]){
    struct sigaction sig;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = User_signal;

    sigaction(SIGUSR1, &sig, NULL);
    
    printf("PID #%d, paused and waiting for action\n", getpid());
    
    pause();
    // while(1){
    //     sleep(1);
    // }
    
    return 0;
}