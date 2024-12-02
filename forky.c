// Kshitij Pingle
// kpingle@csu.fullerton.edu
// Date: October 3, 2023
// Description: This program demonstrates process creation using fork().


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "pattern1.h"
#include "pattern2.h"
#include "pattern3.h"

int main(unsigned int argc, char *argv[]) {

    // Function pointer
    typedef void (*Pattern)(unsigned int n);

    if (argc < 3) {
        fprintf(stderr, "Incorrect amount of arguments\n");
        fprintf(stderr, "Usage: %s <pattern_num> <n>\n", argv[0]);
        return 1;
    }

    int pattern_num = atoi(argv[1]);
    unsigned int n = atoi(argv[2]);

    if ((pattern_num > 3) || (pattern_num < 1)) {
        fprintf(stderr, "Invalid pattern number, please input pattern number from 1 to 3\n");
        fprintf(stderr, "Usage: %s <pattern_num> <n>\n", argv[0]);
        return 1;
    }

    // Initalize function pointer
    Pattern pattern;

    switch (pattern_num) {
        case 1:
            pattern = pattern_1;
            break;
    
        case 2:
            pattern = pattern_2;
            break;

        case 3:
            pattern = Binary_Pattern;
            break;
    
        default:
            pattern = pattern_1;
            break;
    }

    pattern(n);

    return 0;
}