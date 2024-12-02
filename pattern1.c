// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: Program to create a pattern of processes using fork().

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pattern1.h"


void pattern_1 (unsigned int max) {

    for(int i = 0; i < max; i++) {

        if(fork() == 0) {
            fprintf(stderr, "Process 0 creating process %d\n",i+1);
            fprintf(stderr, "Process %d beginning\n", i + 1);
            sleep(1);   // Do some work
            exit(0);
        }
    }
    
    for(int i = 0; i < max; i++) {
        wait(NULL);
        fprintf(stderr, "Process %d exiting\n", i + 1);
    }

}