// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: Program to create a pattern of processes using fork().

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pattern1.h"


void Normal_Pattern (unsigned int n) {

    for(int i = 0; i < n; i++) {

        if(fork() == 0) {
            printf("Process 0 creating process %d\n",i+1);
            printf("Process %d beginning\n", i + 1);
            sleep(2);
            exit(0);
        }
    }
    
    for(int i = 0; i < n; i++) {
        wait(NULL);
        printf("Process %d exiting\n", i + 1);
    }

}