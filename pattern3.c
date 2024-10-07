// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: Add description later.

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pattern3.h"


void Binary_Pattern (unsigned int n) {

    unsigned int i = 0;
    int p = 0;

    // Create 2 child processes
    for (unsigned int j = 0; j < 2; j++) {
        p = fork();

        if (p == 0) {
            // This is the child process
            printf("Child %d (%d) created by parent %d\n", j + 1, getpid(), getppid());
            //sleep(2);
            // exit(0);
        }

        if (j == 2) {
            exit(0);
        }
    }

    for (unsigned int j = 0; j < 2; j++) {
        wait(NULL);
    }

}