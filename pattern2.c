// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: Add description later.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pattern2.h"


void Linear_Pattern (unsigned int n) {

    // Does not work correctly at the moment

    int count = 0;

    for (int i = 0; i < n; ++i) {
        int p = fork();

        if (p == 0) {
            // This is the child process
            printf("Child %d (%d) created by parent %d (%d)\n", count + 1, getpid(), count, getppid());
            count++;
            printf("Process %d (%d) beginning\n", count, getpid());
            sleep(2);
        }
        else {
            printf("Process %d (%d) exiting\n", count, getpid());
            //exit(0);
            break;
        }
    }

    exit(0);

}