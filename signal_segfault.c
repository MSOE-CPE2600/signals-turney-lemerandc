/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Charlie Lemerand
 * 
 * Brief summary of modifications: created the function fault_signal to
 * catch any seg faults
 */


#include <stdio.h>
#include <signal.h>

void fault_signal(){
    printf("A seg fault has occured\n");
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;

    signal(SIGSEGV, fault_signal);

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}