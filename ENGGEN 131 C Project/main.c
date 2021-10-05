//
//  main.c
//  ENGGEN 131 C Project
//
//  Created by Pradyun Setti on 5/10/21.
//
#include <stdio.h>
#include "functions.h"
#include "constants.h"

int main(void) {
    int floor[NUM_ROWS][NUM_COLS];
    
    InitialiseFloor(floor, 'R', 5);
    PrintFloor(floor);
    return 0;
}


