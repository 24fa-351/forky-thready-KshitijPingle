// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: Add description later.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#include "pattern2.h"

// Every child process makes the next child process
void pattern_2(unsigned int max)
{
    fprintf(stderr, "Process 0 (%d) beginning\n", getpid());

    int p = fork();
    if (p == 0)
    {

        fprintf(stderr, "Child 1 (%d) created by process 0 (%d)\n", getpid(), getppid());
        fprintf(stderr, "Process 1 (%d) beginning\n", getpid());

        sleep(1); // Do some work

        if (max > 1)
        {
            // Pass in 2 as the current process number
            make_child_process(max, 2);
        }

        fprintf(stderr, "Process 1 (%d) exiting\n", getpid());
        exit(0);
    }
    else
    {
        wait(NULL);
    }

    fprintf(stderr, "Process 0 (%d) exiting\n", getpid());
    return;
}

void make_child_process(unsigned int max, unsigned int current)
{

    int p = fork();

    if (p == 0)
    {

        fprintf(stderr, "Child %d (%d) created by process %d (%d)\n", current, getpid(), current - 1, getppid());
        fprintf(stderr, "Process %d (%d) beginning\n", current, getpid());

        sleep(1); // Do some work

        if (current < max)
        {
            make_child_process(max, current + 1);
        }

        fprintf(stderr, "Process %d (%d) exiting\n", current, getpid());
        exit(0);
    }
    else
    {
        wait(NULL);
    }

    return;
}