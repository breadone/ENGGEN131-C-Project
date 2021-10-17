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
    
    int rowA, colA, rowB, colB;
    int result, isBlocked;
    InitialiseFloor(floor, 'R', 3);
    AddContainer(floor, 25, 2, 0);
    PrintFloor(floor);
    
    // Move container A:
    isBlocked = LocateContainer(floor, 'A', &rowA, &colA, &rowB, &colB);
    result = MoveContainer(floor, rowA, colA, rowB, colB, isBlocked);
    printf("Result = %d\n", result);
    PrintFloor(floor);
    return 0;
}


