// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: Program to create a pattern of processes using fork().

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pattern1.h"

// All child processes are made by the parent process
void pattern_1(unsigned int max)
{

    fprintf(stderr, "Process 0 (%d) beginning\n", getpid());

    for (int i = 1; i < max + 1; i++)
    {

        if (fork() == 0)
        {
            fprintf(stderr, "Child %d (%d) created by process %d (%d)\n", i, getpid(), 0, getppid());
            fprintf(stderr, "Process %d (%d) beginning\n", i, getpid());
            sleep(1); // Do some work

            fprintf(stderr, "Process %d (%d) exiting\n", i, getpid());
            exit(0);
        }
        else
        {
            wait(NULL);
        }
    }

    fprintf(stderr, "Process 0 (%d) exiting\n", getpid());
}