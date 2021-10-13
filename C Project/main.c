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
    
    int rowA, colA, rowB, colB, isBlocked;
    InitialiseFloor(floor, 'R', 3);
    AddContainer(floor, 9, 3, 0);
    AddContainer(floor, 11, 2, 1);
    AddContainer(floor, 13, 6, 1);
    AddContainer(floor, 49, 2, 0);
    PrintFloor(floor);
    printf("Area Available: %f sq ft\n", FloorAreaAvailable(floor, 10, 5));
    
    isBlocked = LocateContainer(floor, 'A', &rowA, &colA, &rowB, &colB);
    printf("Container A is at: (%d, %d) - (%d, %d) Blocked? %d\n", rowA, colA, rowB, colB, isBlocked);
    
    isBlocked = LocateContainer(floor, 'B', &rowA, &colA, &rowB, &colB);
    printf("Container B is at: (%d, %d) - (%d, %d) Blocked? %d\n", rowA, colA, rowB, colB, isBlocked);
    
    isBlocked = LocateContainer(floor, 'C', &rowA, &colA, &rowB, &colB);
    printf("Container C is at: (%d, %d) - (%d, %d) Blocked? %d\n", rowA, colA, rowB, colB, isBlocked);
    return 0;
}


