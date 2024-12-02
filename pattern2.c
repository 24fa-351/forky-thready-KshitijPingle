// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: Add description later.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pattern2.h"


void pattern_2 (unsigned int max) {
    fprintf(stderr, "Process 0 (%d) beginning\n", getpid());

    int p = fork();
    if (p == 0) {
        // Parent process only creates one child
        fprintf(stderr, "Child 1 (%d) created by parent (%d)\n", getpid(), getppid());
        make_child_process(max, 2);

        fprintf(stderr, "Process 1 (%d) exiting\n", getpid());
        exit(0);
    }
    else{
        wait(NULL);
    }

    fprintf(stderr, "Process 0 (%d) exiting\n", getpid());
    return;
}

void make_child_process(unsigned int max, unsigned int current) {
    fprintf(stderr, "Process %d (%d) beginning\n", current, getpid());

    if (current < max) {
        // Only make one child
        int p = fork();
        
        if (p == 0) {
            fprintf(stderr, "Child %d (%d) created by parent (%d)\n", current, getpid(), getppid());

            // Child process then also makes one child
            make_child_process(max, current + 1);
        }
        else{
            wait(NULL);
        }
    }

    fprintf(stderr, "Process %d (%d) exiting\n", current, getpid());

    return;
}