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

    unsigned int nodes = 0;
    int p = 0;
    int levels = floor(log2(n));
    int num_of_leaves = (n + 1) / 2;

    fprintf(stderr, "Process 0 (%d) beginning\n", getpid());

    for (int i = 0; i < levels; ++i) {

        if (i == levels - 1) {
            // Create Leaves child processes
            for (unsigned int j = 0; j < num_of_leaves; j++) {
                p = fork();

                if (p == 0) {
                    // This is the child process
                    fprintf(stderr, "Child (%d) created by parent %d\n", getpid(), getppid());
                    sleep(2);
                    fprintf(stderr, "Process (%d) exiting\n", getpid());
                    exit(0);
                }
            }

        }
        else {
            // Create 2 child processes
            for (unsigned int j = 0; j < 2; j++) {
                p = fork();

                if (p == 0) {
                    // This is the child process
                    fprintf(stderr, "Child %d (%d) created by parent %d\n", j + 1, getpid(), getppid());
                    sleep(2);

                    break;  // Don't want children to create more children in this level
                }

                if (j == 1) {   // Want to exit after 2 children are created
                    fprintf(stderr, "Process (%d) exiting\n", getpid());
                    exit(0);
                }
            }
        }
    }

    for (unsigned int i = 0; i < n; i++) {
        wait(NULL);
    }

}