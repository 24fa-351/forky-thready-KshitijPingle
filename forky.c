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

    unsigned int pattern_num = atoi(argv[1]);
    unsigned int n = atoi(argv[2]);

    // Initalize function pointer
    Pattern pattern;

    switch (pattern_num) {

        case 1:
            pattern = Normal_Pattern;
            break;
    
        case 2:
            pattern = Linear_Pattern;
            break;

        case 3:
            pattern = Binary_Pattern;
            break;
    
        default:
            pattern = Normal_Pattern;
            break;
    }

    pattern(n);

    return 0;
}