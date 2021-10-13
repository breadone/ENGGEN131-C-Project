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
    
    InitialiseFloor(floor, 'B', 2);
    PrintFloor(floor);
    printf("Available Area: %f sq ft\n", FloorAreaAvailable(floor, 10.5, 25.6));
    return 0;
}


